#include <iostream>
#include <optional>
#include <tuple>
#include <concepts>

// Jai Shree Ram
// Author : Aditya Singh
// Software Testing Triangle check cpp code

enum class TriangleType { Equilateral, Isosceles, Scalene };

consteval bool is_valid_triangle(int a, int b, int c) {
    return (a + b > c) && (b + c > a) && (c + a > b);
}

[[nodiscard]] constexpr std::optional<TriangleType> classify(int a, int b, int c) {
    if (!is_valid_triangle(a, b, c)) return std::nullopt;
    if (a == b && b == c) return TriangleType::Equilateral;
    if (a == b || b == c || a == c) return TriangleType::Isosceles;
    return TriangleType::Scalene;
}

template <typename T>
concept Integral = std::is_integral_v<T>;

auto main() -> int {
    auto input = []<Integral T>() -> std::tuple<T, T, T> {
        std::cout << "Input the sides of the triangle: ";
        T a{}, b{}, c{};
        std::cin >> a >> b >> c;
        return {a, b, c};
    };

    const auto [a, b, c] = input.operator()<int>();

    if (auto result = classify(a, b, c); result.has_value()) {
        auto triangle = result.value();
        const auto triangle_str = [triangle]() -> std::string_view {
            if constexpr (true) {
                switch (triangle) {
                    case TriangleType::Equilateral: return "Equilateral triangle";
                    case TriangleType::Isosceles:   return "Isosceles triangle";
                    case TriangleType::Scalene:     return "Scalene triangle";
                }
            }
        };
        std::cout << triangle_str() << '\n';
    } else {
        std::cout << "Triangle cannot be formed\n";
    }

    return 0;
}
