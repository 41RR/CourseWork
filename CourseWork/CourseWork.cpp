// Исправили вывод пола студента, добавил полный выбор редактирования студента

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

//int addStudent(struct Student s, int n) {
//    FILE* f;
//    errno_t err = fopen_s(&f, "students.txt", "a");
//    if (err != 0) {
//        printf("Ошибка открытия файла\n");
//        return n;
//    }
//    fprintf(f, "%s %s ", s.firstName, s.surName);
//    for (int i = 0; i < MAX_SUBJECTS; i++) {
//        fprintf(f, "%d ", s.marks[i]);
//    }
//    fprintf(f, "\n");
//    fclose(f);
//    return n + 1;
//}
//
//void printStudents() {
//    FILE* f;
//    errno_t err = fopen_s(&f, "students.txt", "r");
//    if (err != 0) {
//        printf("Ошибка открытия файла\n");
//        return;
//    }
//    struct Student s;
//    while (fscanf_s(f, "%s %s", s.firstName, MAX_NAME_LENGTH, s.surName, MAX_NAME_LENGTH) != EOF) {
//        printf("%s %s ", s.firstName, s.surName);
//        for (int i = 0; i < MAX_SUBJECTS; i++) {
//            fscanf_s(f, "%d", &s.marks[i]);
//            printf("%d ", s.marks[i]);
//        }
//        printf("\n");
//    }
//    fclose(f);
//}
//
//int addStudent(struct User s, int n) {
//    FILE* f;
//    errno_t err = fopen_s(&f, "Students.txt", "")
//

struct Date
{
    unsigned short Day; // день
    unsigned short Month; // месяц
    unsigned short Year; // год
};

struct Inicialy
{
    string Name; // имя
    string SurName; // фамилия
    string Otche; // отчество
    Date MyDate = { 0, 0, 0 };
};

struct GP
{
    unsigned short GPyear; // год поступления в вуз
};

struct Kaf
{
    string Kafedra; // название кафедры
};

struct Fac
{
    string Facultet;
};

struct Groups
{
    string NumGroup; // номер группы
};

struct NumZatchet
{
    string Zachet; // номер зачётной книжки
};

struct Gender
{
    string Pol; // пол студента
};

struct Session
{
    string subjectNames[10] = { }; // названия предметов 
    int grades[10] = { }; // оценки по каждому предмету в каждой сессии 
};

struct User
{
    Fac Facul;
    Inicialy Inicy;
    GP Group = { 0 };
    Kaf Kafedrs;
    Groups Gru;
    NumZatchet Zach;
    Gender Sex;
    Session sessions[9] = { }; // максимально 9 сессий
};

int age(int day, int month, int year, int Group)
{
    int current_day = 20; // дата начала приёма документов в вуз
    int current_month = 6;
    int current_year = Group;
    int ages = current_year - year;
    if (month > current_month || (month == current_month && day > current_day))
    {
        ages--;
    }
    return ages;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    User* users = nullptr;
    int numUsers = 0; // счётчик количества студентов
    int capacity = 0; // вместимость студентов
    int choiceSm; // Номер поля для подменю редактирования.
    int choice;
    do
    {
        cout
            << "--------------------------------------------------\n"
            << "Программа по заполнению данных о студентах РТУ МИРЭА.\n"
            << "Выберите действие:\n"
            << "1. Ввод пользователей\n"
            << "2. Вывод всех пользователей\n"
            << "3. Редактировать данные пользователей\n"
            << "4. Удалить пользователя\n"
            << "0. Выход\n--------------------------------------------------\n"
            << "Ваш выбор: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Введите данные о студенте: ";

            User user;

            cout << "\nИмя: ";
            cin >> user.Inicy.Name;
            cin.clear();
            int ch = 0;
            while ((ch = cin.get() != '\n' && ch != EOF));

            cout << "Фамилия: ";
            cin >> user.Inicy.SurName;
            cin.clear();
            while ((ch = cin.get() != '\n' && ch != EOF));

            cout << "Отчество: ";
            cin >> user.Inicy.Otche;
            cin.clear();
            while ((ch = cin.get() != '\n' && ch != EOF));

            int ages = 100;
            do {
                if (ages < 16)
                {
                    cout << "Ошибка! Введите корректную дату\n";
                }
                cout << "День рождения: ";
                cin >> user.Inicy.MyDate.Day;
                cin.clear();

                while ((ch = cin.get() != '\n' && ch != EOF));
                cout << "Месяц рождения: ";
                cin >> user.Inicy.MyDate.Month;
                cin.clear();

                while ((ch = cin.get() != '\n' && ch != EOF));
                cout << "Год рождения: ";
                cin >> user.Inicy.MyDate.Year;
                cin.clear();

                while ((ch = cin.get() != '\n' && ch != EOF));
                cout << "Введите год поступления: ";
                cin >> user.Group.GPyear;
                cin.clear();

                while ((ch = cin.get() != '\n' && ch != EOF));
                ages = age(user.Inicy.MyDate.Day, user.Inicy.MyDate.Month, user.Inicy.MyDate.Year, user.Group.GPyear);
            } while (ages < 16);

            cout << "Факультет(Институт): ";
            cin >> user.Facul.Facultet;
            while ((ch = cin.get() != '\n' && ch != EOF));
            cin.clear();

            cout << "Группа: ";
            cin >> user.Gru.NumGroup;
            while ((ch = cin.get() != '\n' && ch != EOF));
            cin.clear();

            cout << "Кафедра: ";
            cin >> user.Kafedrs.Kafedra;
            while ((ch = cin.get() != '\n' && ch != EOF));
            cin.clear();

            cout << "Номер зачетной книжки: ";
            cin >> user.Zach.Zachet;
            while ((ch = cin.get() != '\n' && ch != EOF));
            cin.clear();

            cout << "Пол студента ( М - мужской/ Ж - женский): ";
            cin >> user.Sex.Pol;
            while ((ch = cin.get() != '\n' && ch != EOF));
            cin.clear();



            if (numUsers >= capacity)
            {
                // увеличиваем ёмкость массива в два раза
                capacity = (capacity == 0 ? 1 : capacity * 2);
                User* newUsers = new User[capacity];
                for (int i = 0; i < numUsers; i++)
                {
                    newUsers[i] = users[i];
                }
                delete[] users;
                users = newUsers;
            }

            users[numUsers] = user;
            numUsers++;
            //}

            break;
        }
        case 2:
        {
            if (numUsers == 0)
            {
                cout << "Список студентов пуст.\n";
            }
            else
            {
                cout << "Список всех студентов:\n";
                for (int i = 0; i < numUsers; i++)
                {
                    cout << i + 1 << ". Имя: " << users[i].Inicy.Name << "\n   Фамилия: " << users[i].Inicy.SurName
                        << "\n   Отчество: " << users[i].Inicy.Otche << "\n   День рождения: " << users[i].Inicy.MyDate.Day
                        << "\n   Месяц рождения: " << users[i].Inicy.MyDate.Month << "\n   Год рождения: " << users[i].Inicy.MyDate.Year
                        << "\n   Год поступления: " << users[i].Group.GPyear << "\n   Факультет(Институт): " << users[i].Facul.Facultet
                        << "\n   Кафедра: " << users[i].Kafedrs.Kafedra << "\n   Группа: " << users[i].Gru.NumGroup
                        << "\n   Номер зачетной книжки: " << users[i].Zach.Zachet << "\n   Пол (М - мужской, Ж - женский): " << users[i].Sex.Pol << endl;
                }

            }

            break;
        }
        case 3:
        {
            if (numUsers == 0)
            {
                cout << "Список пользователей пуст.\n";
            }
            else
            {
                cout << "Введите индекс пользователя (от 1 до " << numUsers << "): ";
                int index;
                cin >> index;
                if (index - 1 >= 0 && index - 1 < numUsers) {
                    do //Имя,фамилия,отчество,день,месяц,год,год поступления
                    {
                        cout << "1.Редактировать имя\n";
                        cout << "2.Редактировать фамилию\n";
                        cout << "3.Редактировать отчество\n";
                        cout << "4.Редактировать день рождения\n";
                        cout << "5.Редактировать месяц рождения\n";
                        cout << "6.Редактировать год рождения\n";
                        cout << "7.Редактировать год поступления\n";
                        cout << "8.Редактировать факультет(институт)\n";
                        cout << "9.Редактировать группу\n";
                        cout << "10.Редактировать кафедру\n";
                        cout << "11.Редактировать номер зачетной книжки\n";
                        cout << "12.Редактировать пол студента\n";
                        cout << "0.Выйти из редактора\n";
                        cout << "Введите поле данных для редактирования: ";
                        cin >> choiceSm;
                        switch (choiceSm) {
                        case 1:
                            cout << "Введите новое имя: \n";
                            cin >> users[index - 1].Inicy.Name;
                            break;
                        case 2:
                            cout << "Введите новую фамилию: \n";
                            cin >> users[index - 1].Inicy.SurName;
                            break;
                        case 3:
                            cout << "Введите новое отчество: \n";
                            cin >> users[index - 1].Inicy.Otche;
                            break;
                        case 4:
                            cout << "Введите новый день рождения: \n";
                            cin >> users[index - 1].Inicy.MyDate.Day;
                            break;
                        case 5:
                            cout << "Введите новый месяц рождения: \n";
                            cin >> users[index - 1].Inicy.MyDate.Month;
                            break;
                        case 6:
                            cout << "Введите новый год рождения: \n";
                            cin >> users[index - 1].Inicy.MyDate.Year;
                            break;
                        case 7:
                            cout << "Введите новый год поступления: \n";
                            cin >> users[index - 1].Group.GPyear;
                            break;
                        case 8:
                            cout << "Введите новую факультет(институт): \n";
                            cin >> users[index - 1].Facul.Facultet;
                        case 9:
                            cout << "Введите новую группу: \n";
                            cin >> users[index - 1].Gru.NumGroup;
                            break;
                        case 10:
                            cout << "Введите новую кафедру: \n";
                            cin >> users[index - 1].Kafedrs.Kafedra;
                            break;
                        case 11:
                            cout << "Введите новый номер зачетной книжки: \n";
                            cin >> users[index - 1].Zach.Zachet;
                            break;
                        case 12:
                            cout << "Введите новый пол студента: \n";
                            cin >> users[index - 1].Sex.Pol;
                            break;
                        default:
                            cout << "Некорректный выбор. Попробуйте еще раз.\n";
                        }
                    } while (choiceSm != 0);
                }
            }
            break;
        }
        case 4:
        {
            if (numUsers == 0)
            {
                cout << "Список пользователей пуст.\n";
            }
            else
            {
                cout << "Введите индекс пользователя (от 1 до " << numUsers << "): ";
                int index;
                cin >> index;
                index--;
                if (index >= 0 && index < numUsers)
                {
                    for (int i = index; i < numUsers - 1; i++)
                    {
                        users[i] = users[i + 1];
                    }
                    numUsers--;
                }
                else
                {
                    cout << "Некорректный индекс.\n";
                    break;
                }
            }
        }
        case 0:
        {
            cout << "До свидания!\n";
            break;
        }
        default:
        {
            cout << "Некорректный выбор. Попробуйте еще раз.\n";
            break;
        }
        }
    } while (choice != 0);

    delete[] users;

    return 0;
}