#include <fstream>
#include <iostream>

#include "core/Common.h"
#include "materials/Diffuse.h"
#include "materials/Glass.h"
#include "materials/Metal.h"


#include "core/Camera.h"
#include "core/Writer.h"
#include "hittables/HittableList.h"
#include "hittables/Sphere.h"
#include "materials/Material.h"

using namespace Rayska;

Color ray_color(const Ray& r, const Hittable& world, int max_depth) {
    Ray ray_out = r;
    auto pixel_color = Color(1.0f, 1.0f, 1.0f);
    int bounces = 0;

    while (bounces < max_depth) {
        HitRecord rec;
        if (world.hit(ray_out, 0.001, inf, rec)) {
            //std::cout << "Hit, ";
            ++bounces;
            Ray scattered;
            if (Color attenuation; rec.mat_ptr->scatter(ray_out, rec, attenuation, scattered)) {
                //std::cout << "attenuating by " << attenuation.x() << " " << attenuation.y() << " " << attenuation.z() << "\n";
                pixel_color = pixel_color * attenuation;
                ray_out = scattered;
            } else {
                //std::cout << "did not scatter\n\n";
                return {0.0f, 0.0f, 0.0f};
            }
        } else {
            const Vec3d unit_direction = unitVector(ray_out.direction());
            const float t = 0.5f * (unit_direction.y + 1.0f);
            return pixel_color * ((1.0f - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0));
        }
    }

    return {0.0f, 0.0f, 0.0f};
}

HittableList random_scene() {
    HittableList world;

    auto ground_material = std::make_shared<Diffuse>(Color(0.5, 0.5, 0.5));
    world.add(make_shared<Sphere>(Point3d(0, -1000,0), 1000, ground_material));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            const auto material_roll = random_float();
            Point3d center(a + 0.9f*random_float(), 0.2f, b + 0.9f*random_float());

            if ((center - Point3d(4, 0.2, 0)).length() > 0.9) {
                std::shared_ptr<Material> sphere_material;

                if (material_roll < 0.8) {
                    // Diffuse
                    auto albedo = Color::random() * Color::random();
                    sphere_material = std::make_shared<Diffuse>(albedo);
                    world.add(make_shared<Sphere>(center, 0.2, sphere_material));
                } else if (material_roll < 0.95) {
                    // Metal
                    Color albedo = Color::random(0.5f, 1.0f);
                    float fuzz = random_float(0.0f, 0.5f);
                    sphere_material = std::make_shared<Metal>(albedo, fuzz);
                    world.add(make_shared<Sphere>(center, 0.2f, sphere_material));
                } else {
                    // Glass
                    sphere_material = std::make_shared<Glass>(1.5);
                    world.add(make_shared<Sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }

    auto material1 = std::make_shared<Glass>(1.5);
    world.add(std::make_shared<Sphere>(Point3d(0, 1, 0), 1.0, material1));

    auto material2 = std::make_shared<Diffuse>(Color(0.4, 0.2, 0.1));
    world.add(std::make_shared<Sphere>(Point3d(-4, 1, 0), 1.0, material2));

    auto material3 = std::make_shared<Metal>(Color(0.7, 0.6, 0.5), 0.0);
    world.add(std::make_shared<Sphere>(Point3d(4, 1, 0), 1.0, material3));

    return world;
}


int main() {
    constexpr float aspectRatio = 3.0f / 2.0f;
    constexpr int imgWidth = 240;
    constexpr int imgHeight = static_cast<int>(imgWidth / aspectRatio);
    constexpr int samplesPerPixel = 25;
    constexpr int maxDepth = 500;

    const std::string filename = "out.ppm";

    const HittableList world = random_scene();

    const Point3d look_from(13, 2, 3);
    const Point3d look_at(0, 0, 0);
    const Vec3d view_up(0, 1, 0);
    constexpr float focusDistance = 10.0f;
    constexpr float aperture = 0.0f;
    const Camera cam(look_from, look_at, view_up, 20, aspectRatio, aperture, focusDistance);

    std::vector<Color> pixels{};
    pixels.reserve(imgWidth * imgHeight);

    constexpr float scale = 1.0f / static_cast<float>(samplesPerPixel);

    for (int y = imgHeight - 1; y >= 0; --y) {
        std::cout << "Scanlines remaining: " << y << "\n";
        for (int x = 0; x < imgWidth; ++x) {
            auto &pixel_color = pixels.emplace_back();

            for (int i = 0; i < samplesPerPixel; ++i) {
                const float x_pos = (random_float() + x) / (imgWidth - 1);
                const float y_pos = (random_float() + y) / (imgHeight - 1);
                Ray r = cam.getRay(x_pos, y_pos);
                pixel_color += ray_color(r, world, maxDepth);
            }

            pixel_color.x = std::sqrt(scale * pixel_color.x);
            pixel_color.y = std::sqrt(scale * pixel_color.y);
            pixel_color.z = std::sqrt(scale * pixel_color.z);
        }
    }

    writePpm(filename, imgWidth, imgHeight, pixels);
}
