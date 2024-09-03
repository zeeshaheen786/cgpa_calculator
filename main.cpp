#include <iostream>
#include <vector>

using namespace std;

// Function to calculate GPA for a single semester
float calculateGPA(const vector<int>& grades, const vector<int>& credits) {
    int totalCredits = 0;
    int totalPoints = 0;
    
    for (size_t i = 0; i < grades.size(); ++i) {
        totalPoints += grades[i] * credits[i];
        totalCredits += credits[i];
    }
    
    return static_cast<float>(totalPoints) / totalCredits;
}

// Function to calculate CGPA over multiple semesters
float calculateCGPA(const vector<float>& gpas, const vector<int>& credits) {
    int totalCredits = 0;
    float weightedGPA = 0;
    
    for (size_t i = 0; i < gpas.size(); ++i) {
        weightedGPA += gpas[i] * credits[i];
        totalCredits += credits[i];
    }
    
    return weightedGPA / totalCredits;
}

int main() {
    int semesters;
    
    cout << "Enter the number of semesters: ";
    cin >> semesters;
    
    vector<float> gpas;
    vector<int> totalCreditsPerSemester;
    
    for (int i = 0; i < semesters; ++i) {
        int subjects;
        
        cout << "Enter the number of subjects in semester " << i + 1 << ": ";
        cin >> subjects;
        
        vector<int> grades(subjects);
        vector<int> credits(subjects);
        
        for (int j = 0; j < subjects; ++j) {
            cout << "Enter grade points for subject " << j + 1 << ": ";
            cin >> grades[j];
            
            cout << "Enter credit hours for subject " << j + 1 << ": ";
            cin >> credits[j];
        }
        
        float gpa = calculateGPA(grades, credits);
        gpas.push_back(gpa);
        
        int totalCredits = 0;
        for (int j = 0; j < subjects; ++j) {
            totalCredits += credits[j];
        }
        totalCreditsPerSemester.push_back(totalCredits);
        
        cout << "GPA for semester " << i + 1 << ": " << gpa << endl;
    }
    
    float cgpa = calculateCGPA(gpas, totalCreditsPerSemester);
    cout << "CGPA: " << cgpa << endl;
    
    return 0;
}
