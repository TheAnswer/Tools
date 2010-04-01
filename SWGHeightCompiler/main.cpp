#include "system.h"

unsigned int getIndex(int x, int y);

int main(int argc, char* argv[]) {
	fstream inputFile;
	fstream outputFile;

	char* nameFormat = "%d %d.bin";
	char fileName[MAX_PATH];

	char yBuffer[320];

	outputFile.open("heightMap.bin", fstream::out | fstream::binary);

	for (int x = -7640; x <= 7640; x += 80) {
		for (int a = 0; a < 80; ++a) {
			for (int y = -7640; y <= 7640; y += 80) {
				// open file and dump a * 80 values.
				sprintf(fileName, nameFormat, x, y);

				inputFile.open(fileName, fstream::in | fstream::binary);

				if (inputFile.fail()) {
					cout << "Could not open " << fileName << "\n";

					return 0;
				}

				inputFile.seekg(getIndex(a, 0));

				inputFile.read(yBuffer, 320);

				inputFile.close();

				outputFile.write(yBuffer, 320);

			}

			// open file and dump value 81;

			sprintf(fileName, nameFormat, x, 7640);

			inputFile.open(fileName, fstream::in | fstream::binary);

			if (inputFile.fail()) {
				cout << "Could not open " << fileName << "\n";

				return 0;
			}

			inputFile.seekg(getIndex(a, 80));

			inputFile.read(yBuffer, 4);

			inputFile.close();

			outputFile.write(yBuffer, 4);
		}
	}


	for (int y = -7640; y <= 7640; y += 80) {
		sprintf(fileName, nameFormat, 7640, y);

		// open file and dump last 80 values.

		inputFile.open(fileName, fstream::in | fstream::binary);

		if (inputFile.fail()) {
			cout << "Could not open " << fileName << "\n";

			return 0;
		}

		inputFile.seekg(getIndex(80, 0));

		inputFile.read(yBuffer, 80 * 4);

		inputFile.close();

		outputFile.write(yBuffer, 80 * 4);
	}

	// open file and dump value 81;

	sprintf(fileName, nameFormat, 7640, 7640);

	inputFile.open(fileName, fstream::in | fstream::binary);

	if (inputFile.fail()) {
		cout << "Could not open " << fileName << "\n";

		return 0;
	}

	inputFile.seekg(getIndex(80, 80));

	inputFile.read(yBuffer, 4);

	inputFile.close();

	outputFile.write(yBuffer, 4);

	//done

	outputFile.close();

	cout << "Finished creating heightMap.bin\n";

	return 1;
}

inline unsigned int getIndex(int x, int y) {
	return ((40 * 2 + 1) * x * sizeof(float)) + (y * sizeof(float));
}
