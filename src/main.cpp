#include <fstream>
#include <iostream>

#include "core/common.hpp"
#include "materials/diffuse.hpp"
#include "materials/metal.hpp"
#include "materials/glass.hpp"


#include "hittables/hittable_list.hpp"
#include "materials/material.hpp"
#include "hittables/sphere.hpp"
#include "core/writer.hpp"
#include "core/camera.hpp"

color ray_color(const ray& r, const hittable& world, int max_depth) {
    ray ray_out = r;
    color pixel_color = {1, 1, 1};
    int bounces = 0;

    while (bounces < max_depth) {
        hit_record rec;
        if (world.hit(ray_out, 0.001, inf, rec)) {
            ++bounces;
            color attenuation;
            if (rec.mat_ptr->scatter(ray_out, rec, attenuation, ray_out)) {
                pixel_color = pixel_color * attenuation;
            } else {
                return {0, 0, 0};
            }
        } else {
            vec3d unit_direction = unit_vector(ray_out.direction());
            float t = 0.5f * (unit_direction.y() + 1.0f);
            return pixel_color * ((1.0f - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0));
        }
    }

    return {0, 0, 0};
}


hittable_list random_scene() {
    hittable_list world;

    auto ground_material = make_shared<diffuse>(color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(point3d(0,-1000,0), 1000, ground_material));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto material_roll = random_float();
            point3d center(a + 0.9*random_float(), 0.2, b + 0.9*random_float());

            if ((center - point3d(4, 0.2, 0)).length() > 0.9) {
                shared_ptr<material> sphere_material;

                if (material_roll < 0.8) {
                    // diffuse
                    auto albedo = color::random() * color::random();
                    sphere_material = make_shared<diffuse>(albedo);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else if (material_roll < 0.95) {
                    // metal
                    auto albedo = color::random(0.5, 1);
                    auto fuzz = random_float(0, 0.5);
                    sphere_material = make_shared<metal>(albedo, fuzz);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else {
                    // glass
                    sphere_material = make_shared<glass>(1.5);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }

    auto material1 = make_shared<glass>(1.5);
    world.add(make_shared<sphere>(point3d(0, 1, 0), 1.0, material1));

    auto material2 = make_shared<diffuse>(color(0.4, 0.2, 0.1));
    world.add(make_shared<sphere>(point3d(-4, 1, 0), 1.0, material2));

    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(make_shared<sphere>(point3d(4, 1, 0), 1.0, material3));

    return world;
}


int main() {
    const float aspect_ratio = 3.0f / 2.0f;
    const int img_width = 300;
    const int img_height = static_cast<int>(img_width / aspect_ratio);
    const int samples_per_pixel = 25;
    const int max_bounces = 10;

    const std::string FILENAME = "out.ppm";

    hittable_list world = random_scene();


    const point3d look_from(13, 2, 3);
    const point3d look_at(0, 0, 0);
    const vec3d view_up(0, 1, 0);
    const float focus_distance = 10.0f;
    const float aperture = 0.0f;
    camera cam(look_from, look_at, view_up, 20, aspect_ratio, aperture, focus_distance);


    std::ofstream outfile(FILENAME);

    outfile << "P3\n";
    outfile << img_width << " " << img_height << "\n";
    outfile << "255\n";


    for (int y = img_height - 1; y >= 0; --y) {
        std::cout << "Scanlines remaining: " << y << "\n";
        for (int x = 0; x < img_width; ++x) {
            color pixel_color{};

            #pragma omp parallel for default(none) shared(samples_per_pixel, x, y, img_height, cam, pixel_color, world)
            for (int i = 0; i < samples_per_pixel; ++i) {
                const float x_pos = (random_float() + x) / (img_width - 1);
                const float y_pos = (random_float() + y) / (img_height - 1);
                ray r = cam.get_ray(x_pos, y_pos);
                color temp_color = ray_color(r, world, max_bounces);

                #pragma omp critical
                {
                    pixel_color += temp_color;
                }
            }

            write_color(outfile, pixel_color, samples_per_pixel);
        }
    }

}
