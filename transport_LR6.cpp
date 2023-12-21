#include <iostream>

#include <string>

#include <cstring>

#include <clocale>


class transport {
        public: transport(std::string model, int Hpower, int age): model(model),
        Hpower(Hpower),
        age(age) {}

        int checkHP() {
                return Hpower;
        }

        virtual int calculateAge() const {
                return age;
        }

        void changeEngine(int new_HP) {
                Hpower = new_HP;
        }

        virtual void showData() const {
                std::cout << "Модель: " << model << std::endl;
                std::cout << "Л/С: " << Hpower << std::endl;
                std::cout << "Год выпуска: " << age << std::endl;
        }

        protected: int Hpower;
        int age;
        std::string model;

};

class Train: public transport {
        public: Train(std::string model, int Hpower, bool isSpeedster, int age): transport(model, Hpower, age),
        isSpeedster(isSpeedster) {}

        void showData() const override {
                std::cout << "Поезд: " << std::endl;
                transport::showData();
                if (isSpeedster == true) {
                        std::cout << "Скоростной" << std::endl;
                } else {
                        std::cout << "Обычный" << std::endl;
                }
        }

        int calculateAge() const override {
                return transport::calculateAge() + 5;
        }

        void changeLicense(bool new_status) {
                if (new_status == true) {
                        std::cout << "Теперь скоростной" << std::endl;
                        isSpeedster = true;
                } else {
                        std::cout << "Тепереь обычный" << std::endl;
                        isSpeedster = false;
                }
        }

        private: bool isSpeedster;
};

class Car: public transport {
        public: Car(std::string model, int Hpower, bool isRacing, int age): transport(model, Hpower, age),
        isRacing(isRacing) {}

        void showData() const override {
                std::cout << "Car: " << std::endl;
                transport::showData();
                if (isRacing == true) {
                        std::cout << "Спортивная" << std::endl;
                } else {
                        std::cout << "Гоодская" << std::endl;
                }
        }

        void changeLicense(bool new_status) {
                if (new_status == true) {
                        std::cout << "теперь спортивная" << std::endl;
                        isRacing = true;
                } else {
                        std::cout << "теперь городская" << std::endl;
                        isRacing = false;
                }
        }
        private: bool isRacing;
};

int main() {
        const int arraySize = 3;
        transport * ts[arraySize];

        ts[0] = new Car("Toyota", 110, true, 4);
        ts[1] = new Train("РЖД", 110000, true, 5);

        int choice = -1;
        int option = 0;
        int min_ts = 0;
        int new_hp = 0;
        bool new_license = false;
        int min_age = 1000;

        std::cout << "Список транспорта" << std::endl;
        std::cout << "Выберите одно действие: " << std::endl;
        std::cout << "1 для Информация" << std::endl;
        std::cout << "2 для Поменять мощность мотора" << std::endl;
        std::cout << "3 для Пересчитать транспорт" << std::endl;

        while (choice != 0) {
                std::cout << "Напишите опцию или 0 для заверешения" << std::endl;
                std::cin >> choice;
                switch (choice) {
                case 0: {
                        choice = 0;
                        std::cout << "Выход из программы" << std::endl;
                        break;
                }
                case 1: {
                        for (int i = 0; i < arraySize; i++) {
                                std::cout << "Транспорт " << (i + 1) << std::endl;
                                ts[i] -> showData();
                        }
                        break;
                }
                case 2: {
                        std::cout << "Выберите лнию которую хотите поменять" << std::endl;
                        std::cin >> option;
                        std::cout << "Напишите новое значенеи лошадинных сил" << std::endl;
                        std::cin >> new_hp;
                        ts[option - 1] -> changeEngine(new_hp);
                        std::cout << "Л/С изменены" << std::endl;
                        break;
                }
                case 3: {
                        for (int i = 0; i < arraySize; i++) {
                                if (ts[i] -> calculateAge() < min_age) {
                                        min_age = ts[i] -> calculateAge();
                                        min_ts = i;
                                }
                        }
                        std::cout << "Самая старая это: " << min_ts + 1 << " линия
                        break;
                }

                default: {
                        std::cout << "Введена неверная цифра,пробуйте еще раз" << std::endl;
                        break;
                }

                }

        }

        for (int i = 0; i < arraySize; ++i) {
                delete ts[i];
        }

        return 0;
}