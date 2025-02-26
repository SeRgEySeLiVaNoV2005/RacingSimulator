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
        if (!typeRace.empty()) cout << "����������, �������� ����� �� 1 �� 3\n\n";
        cout << "����� ���������� � �������� ���������!" << endl
            << "1. ����� ��� ��������� ����������" << endl
            << "2. ����� ��� ���������� ����������" << endl
            << "3. ����� ��� ��������� � ���������� ����������" << endl
            << "�������� ��� ����������: ";
        cin >> typeRace;
        cout << "\33[2J\33[H";
    }
    return stoi(typeRace);
}
int Generator::getLengthPath() {
    system("cls");
    string lp; // length_path

    while (lp.empty()) {
        cout << "������� ����� ��������� (������ ���� ������������): ";
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
        cout << "������ ���� ����������������� ���� �� 2 ������������ ��������" << endl
            << "1. ���������������� ���������" << endl
            << "�������� ��������: ";
        cin >> number;
        system("cls");
    }
}

int Generator::getPreparationOfRace() {
    system("cls");
    string answer_user;

    for (; answer_user != "1" && answer_user != "2";) {
        if (!answer_user.empty()) cout << "����������, �������� ����� �� 1 �� 2\n\n";

        cout << "1. ���������������� ���������" << endl
            << "2. ������ �����" << endl
            << "�������� ��������: ";
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
        {"1", "�������-���������"},
        {"2", "�����"},
        {"3", "�������"},
        {"4", "�������"},
        {"5", "���"},
        {"6", "�������-���������"},
        {"7", "����-������"}
    };
    string transport;
    vector<string> numbers = { "1", "3", "4", "6", "2", "5", "7", "0" };

    while (transport != "0") {
        iter = transports.begin();

        cout << (tr == 1 ? "����� ��� ��������� ����������." : tr == 2 ? "����� ��� ���������� ����������." : "����� ��� ��������� � ���������� ����������.")
            << " ����������: " << lp << endl
            << "������������������ ������������ ��������: ";

        if (!transports.empty()) {
            for (; iter != transports.end(); iter++) {
                if (!(iter == transports.begin())) cout << ", ";
                cout << iter->first;
            }
        }

        cout << endl;
        cout << "1. �������-���������" << endl
            << "2. �����" << endl
            << "3. �������" << endl
            << "4. �������" << endl
            << "5. ���" << endl
            << "6. �������-���������" << endl
            << "7. ����-������" << endl
            << "0. ��������� �����������" << endl
            << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";
        cin >> transport;
        system("cls");

        if (find(numbers.begin(), numbers.end(), transport) == numbers.end()) {
            cout << "����������, �������� ����� �� 0 �� 7\n\n";
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
            cout << "������� ���������������� ������������ ��� ������������� ��������!\n";
        }
        else if (transports.find(transports_name[transport]) != transports.end()) {
            cout << transports_name[transport] << " ��� ���������������!\n";
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

    cout << "��������� �����:" << endl;
    for (int i = 0; i < sort_result.size(); i++) {
        cout << sort_result[i].begin()->first << ". �����: " << sort_result[i].begin()->second << endl;
    }

    for (; answer_user != "1" && answer_user != "2";) {
        if (!answer_user.empty()) cout << "����������, �������� ����� �� 1 �� 2\n\n";

        cout << "\n1. �������� ��� ���� �����" << endl
            << "2. �����" << endl
            << "�������� ��������: ";
        cin >> answer_user;
        system("cls");
    }

    return stoi(answer_user);
}

bool Generator::sortWiner(map<string, double> a, map<string, double> b) {
    return a.begin()->second < b.begin()->second;
}