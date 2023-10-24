#include <iostream>
#include <ctime>
#include <random>
#include <Windows.h>

const int rows = 10;
const int cols = 6;

int main() {
    system("chcp 1251");
    system("cls");
    int array[rows][cols];

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = std::rand() % 10;
        }
    }
    std::cout << "���������� �����:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int shifts;

    std::cout << "������� ������ �����:\n1. ������\n2. ����\n3. �����\n4. ����\n";
    int choice;
    std::cin >> choice;

    std::cout << "������ ������� �����: ";
    std::cin >> shifts;

    switch (choice) {
    case 1:
        // ���� ������
        for (int k = 0; k < shifts; k++) {
            for (int i = 0; i < rows; i++) {
                int temp = array[i][cols - 1];
                for (int j = cols - 1; j > 0; j--) {
                    array[i][j] = array[i][j - 1];
                }
                array[i][0] = temp;
            }
        }
        break;

    case 2:
        // ���� ����
        for (int k = 0; k < shifts; k++) {
            for (int i = 0; i < rows; i++) {
                int temp = array[i][0];
                for (int j = 0; j < cols - 1; j++) {
                    array[i][j] = array[i][j + 1];
                }
                array[i][cols - 1] = temp;
            }
        }
        break;

    case 3:
        // ���� �����
        for (int k = 0; k < shifts; k++) {
            for (int j = 0; j < cols; j++) {
                int temp = array[0][j];
                for (int i = 0; i < rows - 1; i++) {
                    array[i][j] = array[i + 1][j];
                }
                array[rows - 1][j] = temp;
            }
        }
        break;

    case 4:
        // ���� ����
        for (int k = 0; k < shifts; k++) {
            for (int j = 0; j < cols; j++) {
                int temp = array[rows - 1][j];
                for (int i = rows - 1; i > 0; i--) {
                    array[i][j] = array[i - 1][j];
                }
                array[0][j] = temp;
            }
        }
        break;

    default:
        std::cout << "����������� ���� ������� �����." << std::endl;
        return 1;
    }

    std::cout << "��������� �����:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}