#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <chrono>

using namespace std::chrono;

struct studentai
{
    std::string vardas = "Vardas_";
    std::string pavarde = "Pavarde_";
    double galutinis;
    double mediana;
    int eg;
    int vidurkis = 0;
    std::vector<int> Pazymiai;
    int dydis;
};

int main()
{  int stud = 1000;
   srand(time(NULL));
   int dyd = rand() % 5 + 1; //iki 5 pazymiu
   std::cout << "Kiekvienam studentui generuojami " << dyd << " namu darbu pazymiai." << std::endl;
   std::cout << std::endl;
   for (int ciklas = 0; ciklas < 5; ciklas++)
   {
   studentai *st = new studentai[stud];
   auto start0 = high_resolution_clock::now();
   for (int i = 0 ; i < stud; i++)
   {
            std::string sk;
            if (i+1 < 10000000) sk.append("0");
            if (i+1 < 1000000) sk.append("0");
            if (i+1 < 100000) sk.append("0");
            if (i+1 < 10000) sk.append("0");
            if (i+1 < 1000) sk.append("0");
            if (i+1 < 100) sk.append("0");
            if (i+1 < 10) sk.append("0");
            std::string laik = std::to_string(i+1);
            sk.append(laik);
            st[i].vardas.append(sk);
            st[i].pavarde.append(sk);

            for (int z = 0; z < dyd; z++) st[i].Pazymiai.push_back(rand() % 10 + 1);
            st[i].eg = rand() % 10 + 1;
            st[i].dydis = dyd + 1;
            st[i].Pazymiai.push_back(st[i].eg);
   }

    std::string duomenys = "Duomenys_";
    std::string kiekis = std::to_string(stud);
    duomenys.append(kiekis);
    duomenys.append(".txt");
    std::ofstream duom (duomenys);
    duom << "Vardas                  Pavarde                  ";
    for (int i = 1; i <= dyd; i++) duom << "ND" << i << "   ";
    duom << "Egzaminas" << std::endl;
    for (int i = 0; i < stud; i++)
    {
        duom << std::setw(20) << std::left << st[i].vardas << std::setw(20) << std::left << st[i].pavarde << " ";
        for (int j = 0; j < dyd; j++) duom << std::setw(8) << std::left << st[i].Pazymiai[j];
        duom << "  " << st[i].eg << std::endl;
    }
    duom.close();
    auto end0 = high_resolution_clock::now();
    duration<double> diff0 = end0 - start0;
    std::cout << "Failas " << stud << " sugeneruotas per " << diff0.count() << " s\n";
    delete [] st;
    auto start1 = high_resolution_clock::now();
    studentai *naujas = new studentai[stud];
    std::ifstream duomuo (duomenys);
    std::string laikinas;
    for (int z = 0; z < 3 + dyd; z++) duomuo >> laikinas;
    for (int z = 0; z < stud; z++)
    {
        duomuo >> naujas[z].vardas >> naujas[z].pavarde;
        for (int k = 0; k < dyd; k++)
        {
            int t;
            duomuo >> t;
            naujas[z].Pazymiai.push_back(t);
        }
        duomuo >> naujas[z].eg;
    }

    auto end1 = high_resolution_clock::now();
    duration<double> diff1 = end1 - start1;
    std::cout << "Failas " << stud << " nuskaitytas per " << diff1.count() << " s\n";

   for (int i = 0 ; i < stud; i++)
   {   int dydis = naujas[i].Pazymiai.size();
        double mediana;
        sort(naujas[i].Pazymiai.begin(), naujas[i].Pazymiai.end());
        if ((dydis) % 2 == 0)
            {
                double a;
                a = naujas[i].Pazymiai[int(dydis / 2) - 1] + naujas[i].Pazymiai[int(dydis / 2)];
                mediana = a / 2.0;
            }
        else mediana = naujas[i].Pazymiai[dydis / 2];
        naujas[i].mediana = mediana;

        int vidurkis = 0;
        float galvid, galutinis;
        for (int j = 0; j < dydis - 1; j++) vidurkis += (double)naujas[i].Pazymiai[j];
        galvid = (float) vidurkis / (float) (dydis - 1);
        naujas[i].galutinis = galvid * 0.4 + naujas[i].eg * 0.6;
   }
    auto start2 = high_resolution_clock::now();
    int kiekm = 1, kiekd = 1;
    std::vector <int> mazesni;
    int m = 0;
    std::vector <int> didesni;
    int d = 0;
    for (int i = 0; i < stud; i ++)
    {
        if (naujas[i].galutinis < 5.0)
        {
            mazesni.push_back(i);
            m++;
            kiekm++;
        }
        else
        {
            didesni.push_back(i);
            d++;
            kiekd++;
        }
    }
    auto end2 = high_resolution_clock::now();
    duration<double> diff2 = end2 - start2;

    std::cout << "Failas " << stud << " surusiuotas i 2 grupes per " << diff2.count() << " s\n";

    auto start3 = high_resolution_clock::now();
    std::string failasb = "Blogi.studentai_";
    std::string failasg = "Geri.studentai_";
    std::string studb = std::to_string(kiekm - 1);
    std::string studg = std::to_string(kiekd - 1);
    failasb.append(studb);
    failasg.append(studg);
    failasb.append(".txt");
    failasg.append(".txt");

    std::ofstream rez1 (failasb);
    rez1 << std::left << "Vardas                  " << std::left << "Pavarde               " << "Galutinis (Vid.)/Galutinis(Med.)" << std::endl;
    for (int i = 0 ; i < 60; i++) rez1 << "-";
    rez1 << std::endl;
    for (int i = 0; i < kiekm - 1; i++)
    {
        rez1 << std::setw(20) << std::left << naujas[mazesni[i]].vardas << std::setw(20) << std::left << naujas[mazesni[i]].pavarde
        << std::setw(10) << std::right << std::setprecision(3) << naujas[mazesni[i]].galutinis << std::setw(15) << std::right
        << std::setprecision(3) << naujas[mazesni[i]].mediana << std::endl;
    }
    rez1.close();

    std::ofstream rez2 (failasg);
    rez2 << std::left << "Vardas                  " << std::left << "Pavarde               " << "Galutinis (Vid.)/Galutinis(Med.)" << std::endl;
    for (int i = 0 ; i < 60; i++) rez2 << "-";
    rez2 << std::endl;
    for (int i = 0; i < kiekd - 1; i++)
    {
        rez2 << std::setw(20) << std::left << naujas[didesni[i]].vardas << std::setw(20) << std::left << naujas[didesni[i]].pavarde
        << std::setw(10) << std::right << std::setprecision(3) << naujas[didesni[i]].galutinis << std::setw(15) << std::right
        << std::setprecision(3) << naujas[didesni[i]].mediana << std::endl;
    }
    rez2.close();
    auto end3 = high_resolution_clock::now();
    duration<double> diff3 = end3 - start3;
    std::cout << "Failas " << stud << " isvestas i du failus per " << diff3.count() << " s\n";
    std::cout << std::endl;
    delete [] naujas;
    stud *= 10;
   }
}
