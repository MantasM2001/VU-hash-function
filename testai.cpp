#include "testai.hpp"
#include "laikas.hpp"
#include "headeriai.hpp"

void TestoPasirinkimas(int pasirinkimas)
{
    if(pasirinkimas == 1) VartotojoIvedimas();
    if(pasirinkimas == 2) DviejuFailuLyginimas();
    if(pasirinkimas == 3) PoVienaEilute(false);
    if(pasirinkimas == 4) HashuPoruLyginimas();
    if(pasirinkimas == 5) ProcentinisSkirtingumas();
    if(pasirinkimas == 6) 
    {
        PoVienaEilute(true);
        ProcentinisSkirtingumas(0);
        ProcentinisSkirtingumas(1);
        ProcentinisSkirtingumas(2);
        ProcentinisSkirtingumas(3);
    }
}

void DviejuFailuLyginimas()
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
    cout<<"Tas pats failas perhash'intas:    "<<hashas2<<endl;
    cout<<"Pirmo failo hash'ai sutampa = "<<boolalpha<<(hashas1 == hashas2)<<endl;

    cout<<"\n1000 simboliu failo nr.2 hash'as: "<<hashas3<<endl;
    cout<<"Tas pats failas perhash'intas:    "<<hashas4<<endl;
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

void PoVienaEilute(bool kitosHashFunkcijos)
{
    /* double MD5test = 0;
    double SHA1test = 0;
    double SHA256test = 0;
    double Hashtest = 0;
    for(int i = 0; i<100; i++)
    { */
        cout<<"\nHash'inamas failas 'konstitucija.txt po eilute...'\n"<<endl;

        LaikoMatavimas l;
        double visasLaikas = 0;
        double MD5viso = 0;
        double SHA1viso = 0;
        double SHA256viso = 0;
        string failas1 = "test/konstitucija.txt"; //is kur imsim faila
        string eilute;
        vector<string> hashai;

        string tempHash; //kadangi paciu hashu nereikes, tai i cia tiesiog saugosim visus kitu funkciju hash'us (kuri vis perrasys kitu hash'u)

        ifstream in(failas1);

        while(in)
        {
            getline(in, eilute);

            l.reset();
            hashai.push_back(DuomenuHashinimas(eilute));
            visasLaikas += l.elapsed();
            if(kitosHashFunkcijos)
            {
                l.reset();
                tempHash = md5(eilute);
                MD5viso += l.elapsed();

                l.reset();
                tempHash = sha256(eilute);
                SHA256viso += l.elapsed();

                l.reset();
                tempHash = sha1(eilute);
                SHA1viso += l.elapsed();
            }
        }
        in.close();

        cout<<"'"<<failas1<<"' failo hash'avimas (mano funkcija) uztruko "<<visasLaikas<<" s."<<endl;
        if(kitosHashFunkcijos)
        {
            cout<<"MD5 hash'avimas uztruko "<<MD5viso<<" s."<<endl;
            cout<<"SHA256 hash'avimas uztruko "<<SHA256viso<<" s."<<endl;
            cout<<"SHA1 hash'avimas uztruko "<<SHA1viso<<" s."<<endl;
        }

        /* for(int i = 0; i<hashai.size()-1; i++) //jei norim hashus paziuret
        {
            cout<<i<<" hash'as: "<<hashai[i]<<endl;
        } */

    /*     MD5test += MD5viso;
        SHA1test += SHA1viso;
        SHA256test += SHA256viso;
        Hashtest += visasLaikas;
    }
    MD5test /= 100;
    SHA1test /= 100;
    SHA256test /= 100;
    Hashtest /= 100;
    cout<<"\n------------------------------------------------------\n"<<endl;
    cout<<"Vidutiniai laikai: "<<endl;
    cout<<"MD5: "<<MD5test<<endl;
    cout<<"SHA256: "<<SHA256test<<endl;
    cout<<"SHA1: "<<SHA1test<<endl;
    cout<<"Mano funkcija: "<<Hashtest<<endl; */
}

void HashuPoruLyginimas()
{
    vector<string> failas = { "test/poros10.txt", "test/poros100.txt", "test/poros500.txt", "test/poros1000.txt"};
    int kolizijos;
    int visosKolizijos = 0;

    string eilute1;
    string eilute2;
    string hashas1;
    string hashas2;

    for(int i = 0; i<failas.size(); i++)
    {
        kolizijos = 0;
        cout<<"\nPradedamas darbas su failu '"<<failas[i]<<"'...\n"<<endl;
        
        ifstream in (failas[i]);

        while(in)
        {
            getline(in, eilute1);
            hashas1 = DuomenuHashinimas(eilute1);

            getline(in, eilute2);
            hashas2 = DuomenuHashinimas(eilute2);
            if(hashas1 == hashas2 && eilute1 != eilute2) ++kolizijos;
        }
        in.close();
        cout<<"Po "<<i+1<<"-ojo failo ("<<failas[i]<<") eiluciu hashavim'o rasta "<<kolizijos<<" koliziju(-os)."<<endl;
        visosKolizijos+=kolizijos;
    }
    cout<<"\nViso rasta "<<visosKolizijos<<" koliziju(-os)."<<endl;
}

void PanasausFailoGeneravimas(string failas) //procentiniam skirtingumui failu generavimas (naudojant kitus failus)
{
    string output = failas.substr(0, failas.find("."))+"+diff1.txt"; //reikia kad naudojamuose failu pavadinimuose butu tik vienas taskas (antraip turbut neveiks :) ) 
    ifstream in(failas);
    ofstream out(output);

    string eilute1;
    string eilute2;

    while(in)
    {
        getline(in, eilute1);
        eilute2 = eilute1;
        eilute2[0] = eilute1[0] + 1;
        out<<eilute1<<endl<<eilute2<<endl;
    }
}

void ProcentinisSkirtingumas(int f)
{
    string ats;
    vector<string> failas = { "test/poros10.txt", "test/poros100.txt", "test/poros500.txt", "test/poros1000.txt" };
    vector<string> naujiFailai = { "test/poros10+diff1.txt", "test/poros100+diff1.txt", "test/poros500+diff1.txt", "test/poros1000+diff1.txt" };

    while(ats!="y" && ats!="n")
    {
        cout<<"\nAr sugeneruoti failus testavimui (tam bus sukurti nauji modifikuoti failai is koliziju testavimo)? (y/n): ";
        cin>>ats;
        if(ats!="y" && ats!="n") cout<<"\nIveskite atsakyma is naujo.\n"<<endl;
    }
    if(ats=="y")
    {
        for(int i = 0; i<failas.size(); i++)
        {
            PanasausFailoGeneravimas(failas[i]);
            naujiFailai.push_back(failas[i].substr(0, failas[i].find("."))+"+diff1.txt"); //tuo atveju jei naudojami kiti failai ar ju nebuvo ir pan.
        }
    }

    int eiluciuSk = 0;

    string eilute1;
    string eilute2;

    string hashas1;
    string hashas2;

    int skirtingiHex = 0;
    int skirtingiBit = 0;
    float procentaiHex = 0;
    float procentaiBit = 0;

    float bitMin = 100;
    float bitAvg = 0;
    float bitMax = 0;
    float bitMinViso = 100;
    float bitAvgViso = 0;
    float bitMaxViso = 0;

    float hexMin = 100;
    float hexAvg = 0;
    float hexMax = 0;
    float hexMinViso = 100;
    float hexAvgViso = 0;
    float hexMaxViso = 0;

    if(f == 0) cout<<"\nDirbama su mano funkcija...\n"<<endl;
    if(f == 1) cout<<"\nDirbama su MD5 funkcija...\n"<<endl;
    if(f == 2) cout<<"\nDirbama su SHA1 funkcija...\n"<<endl;
    if(f == 3) cout<<"\nDirbama su SHA256 funkcija...\n"<<endl;

    for(int i = 0; i<naujiFailai.size(); i++)
    {
        cout<<"\nPradedamas darbas su failu '"<<naujiFailai[i]<<"'...\n"<<endl;

        eiluciuSk = 0;
        
        ifstream in (naujiFailai[i]);

        while(in)
        {
            getline(in, eilute1);
            getline(in, eilute2);
            if(f==0) 
            {
                hashas1 = DuomenuHashinimas(eilute1);
                hashas2 = DuomenuHashinimas(eilute2);
            }
            else if(f==1)
            {
                hashas1 = md5(eilute1);
                hashas2 = md5(eilute2);
            }
            else if(f==2)
            {
                hashas1 = sha1(eilute1);
                hashas2 = sha1(eilute2);
            }
            else if(f==3)
            {
                hashas1 = sha256(eilute1);
                hashas2 = sha256(eilute2);
            }
            skirtingiHex = 0;
            skirtingiBit = 0;

            for(int j = 0; j<64; j++)
            {
                if(hashas1[j] != hashas2[j]) ++skirtingiHex;

                bitset<8> b1(hashas1[j]);
                bitset<8> b2(hashas2[j]);

                skirtingiBit += (b1 xor b2).count();
            }

            procentaiHex = skirtingiHex / 64.0 * 100.0;
            procentaiBit = skirtingiBit / 512.0 * 100.0;

            bitMin = min(bitMin, procentaiBit);
            hexMin = min(hexMin, procentaiHex);

            bitMax = max(bitMax, procentaiBit);
            hexMax = max(hexMax, procentaiHex);

            bitAvg += procentaiBit;
            hexAvg += procentaiHex;

            ++eiluciuSk;
        }
        in.close();

        bitAvg /= eiluciuSk;
        hexAvg /= eiluciuSk;

        cout<<i+1<<"-ojo failo ("<<failas[i]<<") poru hashavim'o procentiniai 'skirtingumai': "<<endl;
        cout<<"\nSio failo bit min: "<<bitMin<<"%"<<endl;
        cout<<"Sio failo bit max: "<<bitMax<<"%"<<endl;
        cout<<"Sio failo hex min: "<<hexMin<<"%"<<endl;
        cout<<"Sio failo hex max: "<<hexMax<<"%"<<endl;
        cout<<"\nSio failo bit avg: "<<bitAvg<<"%"<<endl;
        cout<<"Sio failo hex avg: "<<hexAvg<<"%"<<endl;

        bitMinViso = min(bitMin, bitMinViso);
        bitAvgViso += bitAvg;
        bitMaxViso = max(bitMax, bitMaxViso);
        hexMinViso = min(hexMin, hexMinViso);
        hexAvgViso += hexAvg;
        hexMaxViso = max(hexMax, hexMaxViso);

        bitMin = 100;
        bitAvg = 0;
        bitMax = 0;
        
        hexMin = 100;
        hexAvg = 0;
        hexMax = 0;
    }
    bitAvgViso /= 4;
    hexAvgViso /= 4;
    cout<<"\n-----------------------------------------------\n"<<endl;
    cout<<"Galutiniai rezultatai: "<<endl;
    cout<<"\nBit min: "<<bitMinViso<<"%"<<endl;
    cout<<"Bit max: "<<bitMaxViso<<"%"<<endl;
    cout<<"Hex min: "<<hexMinViso<<"%"<<endl;
    cout<<"Hex max: "<<hexMaxViso<<"%"<<endl;
    cout<<"\nBit avg: "<<bitAvgViso<<"%"<<endl;
    cout<<"Hex avg: "<<hexAvgViso<<"%"<<endl;
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