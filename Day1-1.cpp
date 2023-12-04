#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int fileArrLength = 1000;
std::string fileArr[fileArrLength];
std::string digitsArr[fileArrLength];

// Return only the digits as a string.
std::string GetJustDigits(std::string input)
{
	std::string digits;
	for (int i = 0; i < input.size(); i++){
		if (isdigit(input[i])){
			digits.push_back(input[i]);	
		}
	}
	return digits;
}

int main() {
	fstream file;
	//Open the File.
	file.open("Day1Input.txt", ios::in);

	if (file.is_open()) {
		string line;
		int numberOfLines = 0;

		while (file.peek() != EOF) {
			while (getline(file, line)) {
				// Save each line from the file into a string array.
				fileArr[numberOfLines] = line;
				numberOfLines++;
			}
		}
	}
	file.close();
	int total = 0;
	for (int i = 0; i < fileArrLength; i++) {
		// Get all numbers from file line text and save into seperate array.
		digitsArr[i] = GetJustDigits(fileArr[i]);

		// Get the first and last number in the string.
		int l = (int)digitsArr[i].length() - 1;
		char first = digitsArr[i][0];
		char last = digitsArr[i][l];

		// Combine the first and last number into a string and convert to an int.
		std::string combined;
		combined += first;
		combined += last;
		int num = stoi(combined);

		// Update total number
		total += num;
	}
	// Display the sum of calibrations.
	cout << total << endl;
	return 0;
}