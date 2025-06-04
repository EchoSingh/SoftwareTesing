#include <iostream>
#include <array>
#include <optional>
#include <format> // Requires C++20
#include <ranges>

// Jai Shree Ram
// Author : Aditya Singh
// Software Testing Next Date cpp code

enum class Product { Lock = 0, Stock = 1, Barrel = 2 };

struct ProductData {
    int count{};
    int min{};
    int max{};
    int unit_price{};
};

consteval auto get_product_specs() {
    return std::array{
        ProductData{0, 1, 70, 45},   // Lock
        ProductData{0, 1, 80, 30},   // Stock
        ProductData{0, 1, 90, 25}    // Barrel
    };
}

std::optional<std::array<int, 3>> input_products() {
    auto specs = get_product_specs();
    std::array<int, 3> inputs{};

    for (size_t i = 0; i < specs.size(); ++i) {
        const auto& [_, min, max, __] = specs[i];
        std::cout << std::format("Enter the total number of {}: ", 
            i == 0 ? "locks" : (i == 1 ? "stocks" : "barrels"));
        
        int value{};
        std::cin >> value;

        if (value < min || value > max)
            return std::nullopt;

        inputs[i] = value;
    }
    return inputs;
}

constexpr int calculate_sales(const std::array<int, 3>& inputs) {
    auto specs = get_product_specs();
    int total = 0;
    for (size_t i = 0; i < specs.size(); ++i)
        total += inputs[i] * specs[i].unit_price;
    return total;
}

constexpr float compute_commission(int sales) {
    if (sales <= 1000)
        return 0.10f * sales;
    if (sales < 1800)
        return 0.10f * 1000 + 0.15f * (sales - 1000);
    return 0.10f * 1000 + 0.15f * 800 + 0.20f * (sales - 1800);
}

int main() {
    if (auto inputs = input_products(); inputs.has_value()) {
        const auto sales = calculate_sales(*inputs);
        const auto commission = compute_commission(sales);

        std::cout << std::format("Total sales: ${}\n", sales);
        std::cout << std::format("Commission: ${:.2f}\n", commission);
    } else {
        std::cout << "Invalid input\n";
    }
    return 0;
}
