# 2_uzd

*Programos release'ai:*
V0.3

- Atliktas refactoring'as: nauji duomenų tipai ir funkcijos perkeltos į atskirus .h ir .cpp failus.
- Exception handling: programa praneša apie kai kuriuos neteisingus įvestus duomenis, neegzistuojančius duomenų failus.

V0.2

- Pridėta funkcija nuskaityti studentų vardus, pavardes ir jų pažymius iš tekstinio failo.
- Dabar skaičiuojama ir išvedama ir vidurkis, ir mediana.
- Rezultatai į ekraną išvedami išrikiuoti abėcėlės tvarka pagal pavardes (+senas apipavidalinimas).

V0.1 

- Programa skaičiuoja pažymių ir egzamino vidurkį (pagal formulę VIDURKIS = nd pažymys * 0,4 + egzamino pažymys * 0,6).
- Programa skaičiuoja visų pažymių (nd + egzamino) medianą.
- Galima įvesti ne vieno, bet daug studentų pažymius, kadangi kiekvieno studento informacijai naudojama struktūra.
- Užduotis realizuota dviem būdais: 1) saugant namų darbų pažymius masyve dinaminėje atmintyje; 2) saugant namų darbų pažymius vektoriuje. Dėl naudojamo dinaminio masyvo / vektoriaus nereikia iš anksto žinoti namų darbų pažymių kiekio.
- Yra galimybė įvedus studento vardą ir pavardę sugeneruoti namų darbų ir egzamino pavyzdžius atsitiktinai.
- Rezultatai į ekraną išvedami apipavidalinti (lygiuoti), vidurkiai / medianos išvedamos 2 skaičių po kablelio tikslumu.
