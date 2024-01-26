#include <iostream>
#include <string>
#include <cmath>
#include <vector>

struct Exercise {
    std::string name;
    double caloriesBurnedPerRep;
};

class FitnessCalculator {
private:
    double totalCalories;

public:
    FitnessCalculator() : totalCalories(0.0) {}

    void calculateCalories(const Exercise& exercise, int sets, int reps, double weight) {
        double caloriesBurned = exercise.caloriesBurnedPerRep * sets * reps * weight;
        totalCalories += caloriesBurned;
    }

    double getTotalCalories() const {
        return totalCalories;
    }
};

int main() {
    FitnessCalculator fitnessCalculator;

    std::cout << "Choose your goal:\n";
    std::cout << "1. Weight Loss\n";
    std::cout << "2. Weight Gain\n";
    int goalChoice;
    std::cin >> goalChoice;

    std::string goal;
    if (goalChoice == 1) {
        goal = "Weight Loss";
    } else if (goalChoice == 2) {
        goal = "Weight Gain";
    } else {
        std::cout << "Invalid choice. Exiting.\n";
        return 1;
    }

    std::cout << "You chose: " << goal << "\n";

    // Predefined list of exercises
    std::vector<Exercise> exercises = {
        {"Running", 0.1},
        {"Cycling", 0.08},
        {"Jumping Jacks", 0.12},
        {"Push-ups", 0.25},
        {"Squats", 0.2},
        // Add more exercises as needed
    };

    std::cout << "\nChoose exercises from the list:\n";
    for (size_t i = 0; i < exercises.size(); ++i) {
        std::cout << i + 1 << ". " << exercises[i].name << "\n";
    }

    int numExercises;
    std::cout << "\nEnter the number of exercises: ";
    std::cin >> numExercises;

    for (int i = 0; i < numExercises; ++i) {
        int exerciseChoice;
        std::cout << "Enter the number corresponding to Exercise " << i + 1 << ": ";
        std::cin >> exerciseChoice;

        if (exerciseChoice >= 1 && exerciseChoice <= static_cast<int>(exercises.size())) {
            Exercise selectedExercise = exercises[exerciseChoice - 1];

            int sets, reps;
            double weight;

            std::cout << "Sets: ";
            std::cin >> sets;
            std::cout << "Reps: ";
            std::cin >> reps;
            std::cout << "Weight (in kg): ";
            std::cin >> weight;

            fitnessCalculator.calculateCalories(selectedExercise, sets, reps, weight);
        } else {
            std::cout << "Invalid exercise choice. Exiting.\n";
            return 1;
        }
    }

    std::cout << "\nTotal Calories " << goal << "d/Gained: " << fitnessCalculator.getTotalCalories() << " calories\n";

    return 0;
}



