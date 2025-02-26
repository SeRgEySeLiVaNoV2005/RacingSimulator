#include "Generator.h"
Generator::Generator(){
    int user_answer = 0;
    while (user_answer != 2) {
        int type_race = getTypeRace();
        TransportVehicle::distanse = getLengthPath();
        map<string, unique_ptr<TransportVehicle>> result = getTransportVehicle(type_race, TransportVehicle::distanse);
        user_answer = getResultRace(move(result));
    }
}

int Generator::getTypeRace() {
    system("cls");
    string typeRace;

    while (!(typeRace == "3" || typeRace == "2" || typeRace == "1")) {
        if (!typeRace.empty()) cout << "Пожалуйста, выбирете число от 1 до 3\n\n";
        cout << "Добро пожаловать в гоночный симулятор!" << endl
            << "1. Гонка для наземного транспорта" << endl
            << "2. Гонка для воздушного транспорта" << endl
            << "3. Гонка для наземного и воздушного транспорта" << endl
            << "Выберите тип транспорта: ";
        cin >> typeRace;
        cout << "\33[2J\33[H";
    }
    return stoi(typeRace);
}
int Generator::getLengthPath() {
    system("cls");
    string lp; // length_path

    while (lp.empty()) {
        cout << "Укажите длину дистанции (должна быть положительна): ";
        cin >> lp;

        for (char& digit : lp) {
            if (!isdigit(digit)) {
                lp = "";
                break;
            }
        }

        system("cls");
    }

    return stoi(lp);
}



void Generator::textWarning() {
    string number;

    for (; number != "1";) {
        cout << "Должно быть зарегистрированно хотя бы 2 транспортных средства" << endl
            << "1. Зарегистрировать транспорт" << endl
            << "Выберите действие: ";
        cin >> number;
        system("cls");
    }
}

int Generator::getPreparationOfRace() {
    system("cls");
    string answer_user;

    for (; answer_user != "1" && answer_user != "2";) {
        if (!answer_user.empty()) cout << "Пожалуйста, выбирете число от 1 до 2\n\n";

        cout << "1. Зарегистрировать транспорт" << endl
            << "2. Начать гонку" << endl
            << "Выберите действие: ";
        cin >> answer_user;
        system("cls");
    }

    return stoi(answer_user);
}


map<string, unique_ptr<TransportVehicle>> Generator::getTransportVehicle(int tr, int lp) {
    system("cls");
    textWarning();

    map<string, unique_ptr<TransportVehicle>> transports;
    map<string, unique_ptr<TransportVehicle>>::iterator iter;
    map<string, string> transports_name = {
        {"1", "Ботинки-вездеходы"},
        {"2", "Метла"},
        {"3", "Верблюд"},
        {"4", "Кентавр"},
        {"5", "Орёл"},
        {"6", "Верблюд-быстроход"},
        {"7", "Ковёр-самолёт"}
    };
    string transport;
    vector<string> numbers = { "1", "3", "4", "6", "2", "5", "7", "0" };

    while (transport != "0") {
        iter = transports.begin();

        cout << (tr == 1 ? "Гонка для наземного транспорта." : tr == 2 ? "Гонка для воздушного транспорта." : "Гонка для наземного и воздушного транспорта.")
            << " Расстояние: " << lp << endl
            << "Зарегестрированные транспортные средства: ";

        if (!transports.empty()) {
            for (; iter != transports.end(); iter++) {
                if (!(iter == transports.begin())) cout << ", ";
                cout << iter->first;
            }
        }

        cout << endl;
        cout << "1. Ботинки-вездеходы" << endl
            << "2. Метла" << endl
            << "3. Верблюд" << endl
            << "4. Кентавр" << endl
            << "5. Орёл" << endl
            << "6. Верблюд-быстроход" << endl
            << "7. Ковёр-самолёт" << endl
            << "0. закончить регестрацию" << endl
            << "Выберите транспорт или 0 для окончания процесса регистрации: ";
        cin >> transport;
        system("cls");

        if (find(numbers.begin(), numbers.end(), transport) == numbers.end()) {
            cout << "Пожалуйста, выбирете число от 0 до 7\n\n";
        }
        else if (transport == "0" && transports.size() < 2) {
            textWarning();
            transport = "";
            continue;
        }
        else if (transport == "0" && getPreparationOfRace() == 1) {
            transport = "";
            continue;
        }
        else if ((tr == 1 && transport != "1" && transport != "3" && transport != "4" && transport != "6") ||
            (tr == 2 && transport != "2" && transport != "5" && transport != "7")) {
            cout << "Попытка зарегистрировать неправильный тип транспортного средства!\n";
        }
        else if (transports.find(transports_name[transport]) != transports.end()) {
            cout << transports_name[transport] << " уже зарегистрирован!\n";
        }
        else {
            switch (stoi(transport)) {
            case 1: transports[transports_name[transport]] = make_unique<AllTerrainBoots>(lp);
                break;
            case 2: transports[transports_name[transport]] = make_unique<Broomstick>(lp);
                break;
            case 3: transports[transports_name[transport]] = make_unique<Camel>(lp);
                break;
            case 4: transports[transports_name[transport]] = make_unique<Centaur>(lp);
                break;
            case 5: transports[transports_name[transport]] = make_unique<Eagle>(lp);
                break;
            case 6: transports[transports_name[transport]] = make_unique<FastCamel>(lp);
                break;
            case 7: transports[transports_name[transport]] = make_unique<FlyingCarpet>(lp);
                break;
            }
        }
    }

    return transports;
}



int Generator::getResultRace(map<string, unique_ptr<TransportVehicle>> result) {
    system("cls");

    string answer_user;
    vector<map<string, double>> sort_result;
    map<string, unique_ptr<TransportVehicle>>::iterator it;
    it = result.begin();

    for (; it != result.end();) {
        sort_result.push_back({ {it->first, result[it->first]->time} });
        ++it;
    }

    sort(sort_result.begin(), sort_result.end(), &Generator::sortWiner);

    cout << "Результат гонки:" << endl;
    for (int i = 0; i < sort_result.size(); i++) {
        cout << sort_result[i].begin()->first << ". Время: " << sort_result[i].begin()->second << endl;
    }

    for (; answer_user != "1" && answer_user != "2";) {
        if (!answer_user.empty()) cout << "Пожалуйста, выбирете число от 1 до 2\n\n";

        cout << "\n1. Провести ещё одну гонку" << endl
            << "2. Выйти" << endl
            << "Выберите действие: ";
        cin >> answer_user;
        system("cls");
    }

    return stoi(answer_user);
}

bool Generator::sortWiner(map<string, double> a, map<string, double> b) {
    return a.begin()->second < b.begin()->second;
}