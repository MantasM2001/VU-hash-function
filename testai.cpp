#include "testai.hpp"
#include "laikas.hpp"
#include "headeriai.hpp"

void TestoPasirinkimas(int pasirinkimas)
{
    if(pasirinkimas == 1) VartotojoIvedimas();
    if(pasirinkimas == 2) HashuPoruLyginimas();
}

void HashuPoruLyginimas()
{
    //4 kintamieji lyginimui
    string hashas1;
    string hashas2;
    string hashas3;
    string hashas4;

    //failu pavadinimai
    string failas1;
    string failas2;

    /////////////////////////////////////////////////////////////
    //failai su 1 simboliu

    cout<<"\nPradedamas darbas su 1 simbolio ilgio failais..."<<endl;

    failas1 = "test/1s.txt";
    failas2 = "test/2s.txt";

    hashas1 = DarbasSuFailu(failas1);
    hashas2 = DarbasSuFailu(failas1);

    hashas3 = DarbasSuFailu(failas2);
    hashas4 = DarbasSuFailu(failas2);

    cout<<"\n1 simbolio failo nr.1 hash'as: "<<hashas1<<endl;
    cout<<"Tas pats failas perhash'intas: "<<hashas2<<endl;
    cout<<"Pirmo failo hash'ai sutampa = "<<boolalpha<<(hashas1 == hashas2)<<endl;

    cout<<"\n1 simbolio failo nr.2 hash'as: "<<hashas3<<endl;
    cout<<"Tas pats failas perhash'intas: "<<hashas4<<endl;
    cout<<"Antro failo hash'ai sutampa = "<<boolalpha<<(hashas3 == hashas4)<<endl;

    cout<<"\nSiu failu hashai nesutampa = "<<boolalpha<<(hashas1 != hashas3)<<endl;

    cout<<"------------------------------------------------------"<<endl;

    //failai su 1 simboliu
    /////////////////////////////////////////////////////////////
    //failai is 1000 random simboliu

    cout<<"\nPradedamas darbas su 1000 simboliu ilgio failais..."<<endl;

    failas1 = "test/1000s1.txt";
    failas2 = "test/1000s2.txt";

    hashas1 = DarbasSuFailu(failas1);
    hashas2 = DarbasSuFailu(failas1);

    hashas3 = DarbasSuFailu(failas2);
    hashas4 = DarbasSuFailu(failas2);

    cout<<"\n1000 simboliu failo nr.1 hash'as: "<<hashas1<<endl;
    cout<<"Tas pats failas perhash'intas: "<<hashas2<<endl;
    cout<<"Pirmo failo hash'ai sutampa = "<<boolalpha<<(hashas1 == hashas2)<<endl;

    cout<<"\n1000 simboliu failo nr.2 hash'as: "<<hashas3<<endl;
    cout<<"Tas pats failas perhash'intas: "<<hashas4<<endl;
    cout<<"Antro failo hash'ai sutampa = "<<boolalpha<<(hashas3 == hashas4)<<endl;

    cout<<"\nSiu failu hashai nesutampa = "<<boolalpha<<(hashas1 != hashas3)<<endl;

    cout<<"------------------------------------------------------"<<endl;

    //failai is 1000 random simboliu
    /////////////////////////////////////////////////////////////
    //failai, kurie skiriasi tik 1 simboliu (ilgis = 1500)

    cout<<"\nPradedamas darbas su 1500 simboliu ilgio failais (su 1 skirtingu simboliu)..."<<endl;

    failas1 = "test/1500+diff1.txt";
    failas2 = "test/1500+diff2.txt";

    hashas1 = DarbasSuFailu(failas1);
    hashas2 = DarbasSuFailu(failas1);

    hashas3 = DarbasSuFailu(failas2);
    hashas4 = DarbasSuFailu(failas2);

    cout<<"\n1500 simboliu failo nr.1 hash'as: "<<hashas1<<endl;
    cout<<"Tas pats failas perhash'intas:    "<<hashas2<<endl;
    cout<<"Pirmo failo hash'ai sutampa = "<<boolalpha<<(hashas1 == hashas2)<<endl;

    cout<<"\n1500 simboliu failo nr.2 hash'as: "<<hashas3<<endl;
    cout<<"Tas pats failas perhash'intas:    "<<hashas4<<endl;
    cout<<"Antro failo hash'ai sutampa = "<<boolalpha<<(hashas3 == hashas4)<<endl;

    cout<<"\nSiu failu hashai nesutampa = "<<boolalpha<<(hashas1 != hashas3)<<endl;

    cout<<"------------------------------------------------------"<<endl;
}

/* void FailoGeneravimas(int ilgis, bool simbolioSkirtumas) //might add later
{
    srand(time(NULL));

    int sk;
    char simbolis;
    string tekstas;

    for (int i = 0; i<ilgis; i++)
    {
        sk = rand() % 93 + 32;
        simbolis = sk;
        tekstas += simbolis;
    }
    string failas = "test\test"+ilgis;
    ofstream out(failas);
    out<<tekstas;
    out.close();

    if (simbolioSkirtumas)
    {
        failas += "1skirt"; 
        sk = tekstas[0]+1;
        simbolis = sk;
        tekstas[0] = simbolis;
        ofstream out(failas);
        out<<tekstas;
        out.close();
    }
} */