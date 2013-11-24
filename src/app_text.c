#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"


#define MY_UUID { 0x9C, 0x89, 0x24, 0xE9, 0x1B, 0xBC, 0x45, 0x7A, 0xB9, 0x92, 0x63, 0x98, 0xB6, 0xF3, 0xFA, 0xD3 }
PBL_APP_INFO(MY_UUID,
             "IT KPI", "Erik Marke", //based on Mikulas work.
             1, 0, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_STANDARD_APP);

Window window;

TextLayer text_layer;

int page = 0;
const char *texts[24];
bool light = false;

void populateTexts()
{
  // GENERATE FROM texty.php

/* BEGINTEXT */
texts[0] = "GSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - BB - Bridgetown 7 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - BR - São Paulo 206 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - CA - Toronto 216 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - MX - Mexico City 144 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - USA - Alpharetta 68 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - USA - Armonk 935 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - USA - Boise 3 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - USA - Calabasas 61 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - USA - Chicaco 90 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - USA - Dallas 28 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - USA - Fort Wayne 227 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - USA - Hiawatha 5 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - USA - Manchester 52 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - USA - Miami 51 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - USA - Needham 5 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - USA - New York 365 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - USA - Overland Park 431 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - USA - San Francisco 24 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - USA - Schaumburg 104 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - USA - Southfields 7 User\nGSS: Location-based Standard IT Services - Location-based Services Americas\nLocation-based Service - USA - Windsor 69 User\n"; 
texts[1] = "GSS: Location-based Standard IT Services - Location-based Services Asia Pacific\nLocation-based Service - AU - Sydney 170 User\nGSS: Location-based Standard IT Services - Location-based Services Asia Pacific\nLocation-based Service - CN - Beijing 108 User\nGSS: Location-based Standard IT Services - Location-based Services Asia Pacific\nLocation-based Service - HK - Hongkong 221 User\nGSS: Location-based Standard IT Services - Location-based Services Asia Pacific\nLocation-based Service - IN - Bangalore (ODC) 941 User\nGSS: Location-based Standard IT Services - Location-based Services Asia Pacific\nLocation-based Service - IN - Chennai (ODC)  119 User\nGSS: Location-based Standard IT Services - Location-based Services Asia Pacific\nLocation-based Service - IN - Gurgaon (ODC) 353 User\nGSS: Location-based Standard IT Services - Location-based Services Asia Pacific\nLocation-based Service - IN - Hyderabad (ODC) 46 User\nGSS: Location-based Standard IT Services - Location-based Services Asia Pacific\nLocation-based Service - IN - Mumbai 40 User\nGSS: Location-based Standard IT Services - Location-based Services Asia Pacific\nLocation-based Service - JP - Tokyo 78 User\nGSS: Location-based Standard IT Services - Location-based Services Asia Pacific\nLocation-based Service - KP - Seoul 34 User\nGSS: Location-based Standard IT Services - Location-based Services Asia Pacific\nLocation-based Service - MY - Kuala Lumpur 14 User\nGSS: Location-based Standard IT Services - Location-based Services Asia Pacific\nLocation-based Service - SG - Singapore 182 User\n"; 
texts[2] = "GSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - other locations 598 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - AE - Dubai 9 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - CH - Zurich 3847 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - DE - Munich 564 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - DK - Copenhagen 24 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - ES - Madrid 21 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - FR - Paris 70 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - GB - Folkestone 138 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - GB - Gloucester 22 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - GB - Hitchin 17 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - GB - London 899 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - GB - Telford 146 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - IL - Tel Aviv 14 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - IT - Milano 6 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - IT - Rome 47 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - LU - Luxembourg 28 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - LV - Riga 264 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - NL - Amstelveen 28 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - SA - Cape Town 48 User\nGSS: Location-based Standard IT Services - Location-based Services Europe  Middle East & Africa\nLocation-based Service - SK - Bratislava 719 User"; 
texts[3] = "GSS: Location-based Standard IT Services - Workplace Hardware\nLight Notebook Hardware Package 4184 Device\nGSS: Location-based Standard IT Services - Workplace Hardware\nLoan Desktop PC 138 Device\nGSS: Location-based Standard IT Services - Workplace Hardware\nLoan Mobile Phone 10 Device\nGSS: Location-based Standard IT Services - Workplace Hardware\nLoan Notebook 378 Device\nGSS: Location-based Standard IT Services - Workplace Hardware\nPower Desktop Hardware Package 2394 Device\nGSS: Location-based Standard IT Services - Workplace Hardware\nStandard Desktop Hardware Package 604 Device\nGSS: Location-based Standard IT Services - Workplace Hardware\nStandard Notebook Hardware Package 7089 Device"; 
texts[4] = "GSS: Non-location-based Standard IT Services - Employee Lifecycle Services\nEmployee Off-boarding 359 Request\nGSS: Non-location-based Standard IT Services - Employee Lifecycle Services\nEmployee On-boarding 305 Request\nGSS: Non-location-based Standard IT Services - Employee Lifecycle Services\nEmployee Transfer 38 Request\nGSS: Non-location-based Standard IT Services - IT Support Add-on Services\nPremium Support - Executive Add-on 75 User\nGSS: Non-location-based Standard IT Services - IT Support Add-on Services\nPremium Support - Line of Business Add-on 29 User\nGSS: Non-location-based Standard IT Services - IT Support Base Services\nIT Customer Service Package 12913 User\nGSS: Non-location-based Standard IT Services - Organisation & Project Data Services\nShared folders for Organisational- & Project Teams 220370 Gigabyte\nGSS: Non-location-based Standard IT Services - Organisation & Project Data Services\nTeam Mailbox/Database Data 6964 Gigabyte\nGSS: Non-location-based Standard IT Services - Organisation & Project Data Services\nTeam Lotus Notes Mailbox/Database 3005 Mailbox"; 
texts[5] = "GSS: Personal IT Workplace Solutions - Mobile & Smartphone Services\nAccess to email  calendar and contacts for private iPhones/iPads 2765 Device\nGSS: Personal IT Workplace Solutions - Mobile & Smartphone Services\nCorporate mobile phone corporate service (incl SIM/voice plan) 5328 Device\nGSS: Personal IT Workplace Solutions - Mobile & Smartphone Services\nCorporate BlackBerry with access to email  calender and contacts 3356 Device\nGSS: Personal IT Workplace Solutions - Personal IT Workplace Core Services\nPersonal Data Directory 71559 Gigabyte\nGSS: Personal IT Workplace Solutions - Personal IT Workplace Core Services\nPersonal Mail Data 55871 Gigabyte\nGSS: Personal IT Workplace Solutions - Personal IT Workplace Core Services\nIT User base package 12913 User\n GSS: Personal IT Workplace Solutions - Personal IT Workplace Core Services\nIT User extension add-on 12870 User\n GSS: Personal IT Workplace Solutions - Personal IT Workplace Solution Add-ons\nRemote Access for Notebook Add-on 11282 Device\nGSS: Personal IT Workplace Solutions - Personal IT Workplace Solution Add-ons\nIndividual Software Packages Add-on 716026 SW Package\nGSS: Personal IT Workplace Solutions - Personal IT Workplace Solution Add-ons\nPrinter@home Add-on 24 User\nGSS: Personal IT Workplace Solutions - Personal IT Workplace Solution Add-ons\nTrader Package Add-on 55 User";
texts[6] = "7 Klasicismus 17--18s Fr| na antiku, --cit+rozum podrízení, óda epos tragédie charakter.komedie satira bajka| P Corneiile Cid, J Racine Faidra, Moliere Podvodník, Zdravý nemocný, Lakomec, Mizantrop, C Goldoni Sluha 2 pánu| osvícen 18s Diderot, Pierre B Figarova svatba, Voitare Candide, J Swift Gulliver| preromant 2p18s --chladný racional +prozitek Sturm und Drang, JW Goethe Utrpení ml Werthera, Faust| JJ Rousseau O společenské smlouvě, Emil, čili o výchově| ";
texts[7] = "8 Obrození 3t18s--1p19s| #obranná 70l--19s, krisitelé čj, J Dobrovský Zevrubná mluvn jaz čs (GE), VM Kramerius| div V Kotcích, Stavovské, Vlast div Bouda| thám druz Václav T Básně v reči vázané| puchmajer. AJ P Rýmovník| #ofenz 19s--20l19s dohnání E, česky, rukopisy, J Jungmann Slovník Čs--Ně, F Palacký otec národa, Jan Kollár Slávy dcera, FL Čelakovský Ohlas p rus/čes| VK Klicpera Rohovín| #vyvrch 30--50l19s romantismus, panslav> austro, biedermeier, lyr--epic balady, KH Mácha Máj, KJ Erben Kytice, Němcová Babička, JK Tyl Fidlovačka, KH Borovský epigramy| ";
texts[8] = "9 Romantismus 18s--1p19s| --racional +subjektivismus iluze legendy mystika láska lidské nitro aktivní odpor, hrdina splývá s autorem, končí tragicky| hist román, povídka, lyr--ep balada, dram básen, moderní epos| W Scott Ivanhoe, GG Byron C--Haroldova, PB Shelley Odpotaný Prometh, Alex Sergej Puskin Evzen Oněgin, Mich Lermontov Démon, N Hawthorne Sarl písm, EA Poe, Viktor Hugo Chrám m bozí v Parízi, Grimmové Pohádky| Čechy: viz konec 8/| ";
texts[9] = "10 2p 19s| #májovci rozvoj demokratické spol, lidovost, preklady, Almanach Máj, Jan Neruda Knihy versu, Písně kosmické, Pov malostr, Vítězslav Hálek Večerní písně, Jakub Arbes Newtonuv mozek| #lumírovci umění pro u, na světo úrověn, odsuzují pruměr, časpis Lumír, preklady, navazují na májovce, Josef V Skládek Zvony a zvonky, Jaroslav Vrchlický Zlomky epopeje, Noc na Karlstejně| #ruchovci 70+80l19s umění pro národ, propojení s tradicemi, proti lumírov, Almanach Ruch, Svatopluk Čech Evropa, Slavie, Výlet p Broučka, Eliska Krásnoh Hubička| ";
texts[10] = "11 #Realismus 20+30l19s| +vztah k prírodě a společnosti, kritický realismus analýza poměru| román r.kronika drama| #natur 60+70l19s predetermin pesimismus +detaily, napodobení prírody| Rusko zbytečný čl nihilismus, Nikol Vas Gogol Mrtvé duse, Revizor, Ivan Alexa Gončarov Oblomov, Anton Pavl Čechov Chameleon, Lev Niko Tolstoj Vojna a mír, Fjod Michajl Dostoj Zločin a trest, Ch Dickes Oliver Twist, L Carroll Alenka, J Swift, M Twain, Herm Melville, Honore dBalzac Otec Goriot, Gust Flaubert p Bovaryova, Emile Zola Zabiják, Henrik Ibsen drama ala thése Peer Gynt, H Christ Andersen Oskliv káčátko| ";
texts[11] = "12 Drama 19s| #attic rcko: Thespis1 Aischylos2 Sofokles3, Aristofanes old, Menandros new, Euripides #Rím Plautus, Terentius| #stred náboz misterie miracula, karneval sotie morality| #renes komedie plástě a dýky, kolekt drama Lope dVega F Ovejuna, Shakespr| #baroko comedia dellArte, ČR lidová tvorba| #klasic P Corneile Cid, J Racine Faidra, Moliére Lakomec| #ČNO div v Kotcích Stavovské Loutkové Vlast div Bouda, Don Giovanni, VK Klicpera Rohovín č, JK Tyl Fidlovačka, Prozatimní div, 1868 zákl kám, 81 open Smetanov Libusí| #prerom Johan Wv Goethe Faust| #roman Vic Hugo Cromwell| #real Gogol Mrtvé duse, Revizor, Čechov Visnov sad, H Ibsen Peer Gynt, A Jirásek Jan Hus, Stroupeznický Nasi furianti, Mrstíkové Marysa| ";
texts[12] = "13 Prelom 19/20s| --pozitiv optimis real natural| #dekad symbol sex alko kult rozpad a zánik smrti --buh| #lartprlrt parnasisté Současný p, umění ideál krásy Sully Prudhomme| #symbol mlhavost retězení, Jean Moreas Manifest symb| #impres synestezie asociace subjektiv Claude Monet, André Gide| #civilis W Whitman Stébla trvy volný vers, oslava civ| #novoklas #unanimismus #secese --tradic +zhudeb| #prokletí P Verlain zakl symbolis imaginace P. b, Saturnsk b, Ch Baude, JA Rimb| Alfred Jarry Král Ubu, O Wilder Obraz DG| #Č Moderna --1900, FX Salda Manifest Čm, JS Machar Confiteor, Brezina Stav chrám, F Geller, Bezruč, Srámek, Viktor Dyk, Hlaváček, SK Neumann, K Čapek Alamanach na r1914| ";
texts[13] = "14 Buriči| prekonání individualismu, sblízení se zivotem, odpor ke společnosti| SK Neumann čspis Nový kult, socialis, Kniha mládí a vzdoru, Karel Toman prilnutí k rodné zemi, F Srámek vitalismus Zivota bído, Bezruč sociální poezie Slezké písně, V Dyk satira a skepse Milá 7 loupezníku, SKN+Čapek Almanach na r1914 odmítnutí individual a symbolis| čspisy Moderní revue Lidové noviny| #dekadence animalita pruchod pudum a vásním| #anarchismus bohémský zivot, odmítnutí státu a autority, sdělná poezie| #antimilitarismus| #vitalismus| ";
texts[14] = "15 WWI| ztracená generace, FS Fitzgeral Velký Gatsby, TS Eliot Pustina, E Hemingway, metoda ledovce Komu zvoní hrana, EM Remarque Na z front klid, Isaak Babel obraz absurdity Rudá jízda osud 1 v cyklu povídek, Romain Rolland protifasist Petr a Lucie kontrast války a lásky| #ČR próza bezprostrední Frána Srámek, legionárská F Langer, 1 ve válce J Hasek| #poez Jirí Wolker Host do domu, Tězká hodina názorová proměna, Josef Hora civilismus, vitalismus Struny ve větru, Jaroslav Seifert Město v slzách| ";
texts[15] = "16 Drama 1p 20s| moderna, avantgarda, absurdit, ep div, exist dram, model dram absur| Antonin Artaud manifest Divadlo hruzy, GB Shaw soc diskus komed, August Strindberg Tanec Smrti, Mxim Gorkij natural cnosti v bahně spol Na dně, Lgi Pirandelo div na div vypravěč psychoanal 6 postav hledá autora, Eugene Gldstone ONeil Smutek slusí Elektre, Berto Brecht ep div antiiluziv zcizovac fx Sestáková opera, A Camus exist drama Cizinec model abs dram Caligula, J--P Sartre hry o abs Mouchy| #Čechy ofic div, neofic div: Revoluč scén, Dědrasbor, Červená7 písně hardomal, avantg d: Osvoboz d poetismus lyrismus groteska forbín V+W Vest pocket revue, Balada z hadr, protifas: KČ Bílá nemoc| ";
texts[16] = "17 Próza 1p 20s #WWI ztracená generace| #WWII lenini marxi nové pojetí času, filoz ziv elán, exist pragmat futur kub kubof expr dada surr abs konstrukt funkc, J--P Sartre, moderní próza skepse rezignace detabuiz, mimetický proud čas posloup introspekt| R Rolland román reka PaL, Ant d Saint--E Citadela Malý princ, André Breton surr Nadja, André Gide román v r Penězokazi, Marcel Proust Hledání ztr času, FS Fitz, E Heming, Mich Bulgakov| #válka Srámek Langer Hasek, imaginace Vančura Rozmarné léta Mark Lazar, demokrat proud Čapek Poláček Muzi v ofs, psycholog Jar Havlíček Neviditel, spol a soc Iv Olbracht Nikola Suh, rural, katolic, expr sym surr Ladi Klíma Utrpení kníz Stern, hist Frantisek Kubka, humor Zdeněk Jirotka Saturnin| ";
texts[17] = "18 Poezie 1p 20s| poetis surreal reflex+meditav lyr duchov kresť exist| Guillaume Apollin kubofut predchud surr polytem asoc osvob slov Pásmo, FT Marinetti Manif futur odmít konvencí, Vele Chleb zaumný jazyk futuris, Tris Tzara Mani Dada vs staré konvence +svoboda mysli spontán mystif, André Bret M surr psychycký atmtsms, Georg Trakl expres reflexe morbidita, Christ Morgenstern imaginace Sibenič verse, TS Eliot symbol imagin Pustina, Serg Jesenin imazin Krčemná Moskva| #ČR: J Wolker proletár Host do domu, Tězká hod, Konst Bieb S lodí, Jos Hora Struny ve větru, Vítě Nezval poetis postp sur Absolutní hrobar, Vlad Holan abs^abs, Jirí Orten exist odcizen, Fr Hrubín Rmnce pro kríd, J Seifert Na vlnách TSF poetis, Jaro sbojem postp, země v ohr Zhasněte světla, okupace Vějír B Němc, Vsechny krásy světa| ";
texts[18] = "19 WWII #proti fasi KČ Bílá nemoc, V+W Balada z hdr, Vítě Nezv Manon Lescaut, Vlad Holan 9/1938, Seifert Zhasněte světla| #dokum Chrchill, Karl Jaspers Otázka viny| #heroický rus tendenční Boris Polevoj, Michail Solochov Osud člověka| #satirické Norman Mailer Nazí a mrtví, Joseph Heller Hlava XXII| #koncentr EM Remarque Jiskra zivota, Will Styron Sofiina Volba, Thomas Keneally Schinderuv seznam| #ČR bezpr Jan Drda Němá barik, Jul Fučík, V Rezáč, Jir Weil Zivot s hvězdou, Vítě Nezv 5min za městem, Jir Orten, F Hrubín Hirosima #50--60l Norbert Frýd Krabice zivých, Ladis Grosman Obchod na korze, Josef Skvor Zbabělci, Arnost Lustig, Ladistav Fusk Spalovač mrtvol #70+ Ota Pavel Smrt krásných srncu| ";
texts[19] = "20 Svět 2p 20s| #absurdní antidrama Ionesco Beckett| #WWII| #exist Karl Jaspers Otázka viny, Albert Camus, JP Sartre| #neoreal dokumentár Alberto Moravia Horalka| #bítníci hispers vs squares, Allen Ginsb, Jack Kerouac Na cestě, Law Ferl, Charl Bukowsi| #RMM #magic real Mich Bulgakov Mistr a Mark| #postmod dvojúrovn Vladimir Nabokov Lolita, H Murakami, Umberto Eco Jméno ruze| #experi Jackques Prévert| #rus Boris Pasternak, Alex Solzenicin| #scifi Isaac Asimov, Ray Bradbury 451F, Will Gibson, HGWells, Orwell, JRRT, Arthur C Clarke 2001| ";
texts[20] = "21 Česká 2p 20s oficiální| #válečné bezpr: Jan Drda, Jul Fučík, Vác Rezáč Nástup, 50--60l: Norbert Frýd Krabice ziv, Lad Fuks Spalovač mrtvol, 70l+: Ota Pavel Smrt krásných srncu| #hist Vlad Neff, Vlad Korner Údolí včel| #obr soudob čl Vlad Páral Milenci a vrazi, Radek John Memento, Mich Viewegh| #scifi Jan Weiss Dum o 1000p, Ondrej Neff Jádro pudla| #budovat V Rezáč, Jan Procházka| #humorist Miro Horníček, Fr Nepil, Milo Svandr Černí baroni, Ladis Pecháček Jak svět prich o b| Ivan Klíma pokračovatel čapk tradice, Boh Hrabal Postriziny, Ostre sledované vlaky";
texts[21] = "22 Česká poezie 2p 20s| #povál Skupina42 Jind Chalupecký, Jarní Alma básnický Jirí Orten, Skupina RA Ludvík Kundera| #Ohnice Kam Bednár| #Rudé pr Jirí Hájek| #MlFronta Edu Petisk| #surr Jind Heisler| #květnáci Miro Holub Nás vsední den je pevnina| #čsps Host do domu Oldrich Mikulásek| #čsps Tvár V Havel, Jos Topol| #pocity gen 60l Jos Kainar, Vác Hrabě, Jir Kolár, Vlad Holan, Reynek, Rotrekl, Renč, Kryl| #kult kádr Čes svaz ml #katolič #undergr Egon Bondy Totální realsms, Vodseďálek, Hrabal, Boudník, Ivan Magor Jirous Mag labutí písně| #písničkári Nohavica, Kryl| #nové tváre poezie Jirí Kolár Prometheova játra, Jan Skácel Hodina mezi psem a vlkem| ";
texts[22] = "23 Drama 2p 20s| abs l antidr, --děj psych prokresl sdělnost +devalvace jaz, odcizeno, banální míjejí dialogy| Eugene Ionesco 1.abs Zidle, Samuel Beckett lidská bezmocnost pasivita Čekání na Godota, Tennessee Williams lidské nitro, tuctoví hrdinové odcizen Tram do stan Touha, Arthur Miller Smrt obchod cest, Eduard Albee model drama Kdo se bojí Virg Woolf? David A Mamet Oleanna| #dokum Ferdi Peroutka Oblak a valčík| #pohád Jan Drda Hrátky s čertem| #hist #bás Vítě Nezval Manon Lescaut| #satira komedie Vratislav Blazek Starci na chmelu, Nové div satiry, d Za branou, Semafor písničkári Slitr, Činoherní klub, Studio Y, d Na provázku, d Járy Cimrmana| ";
texts[23] = "24 Samizdat| exil nakl 68 Publishers Index| e čsps Svědectví Listy Proměny| sam čsps Vokno Revolver revue| sam edice Petlice Edice expedice| Arnost Lustig, Jirí Mucha, Vác Černý, Boh Hrabal Perlička na dvě Postriziny Ostre sled v, Jách Topol Sestra, Ivan Klíma Milenci na jednu noc, Pavel Tigrid svědomí čs národa, Milan Kundera Směsné lásky, Josef Skvorecký Zbabělci, Tankový prapor, Ludvíc Vaculík Jak se dělá chlapec| ";
/* ENDTEXT */

}

void drawPage(int id)
{
  text_layer_set_text(&text_layer, texts[page]);
}

void select_single_click_handler(ClickRecognizerRef recognizer, Window *window) {
  (void)recognizer;
  (void)window;
  light = !light;
  light_enable(light);
}

void down_single_click_handler(ClickRecognizerRef recognizer, Window *window) {
  (void)recognizer;
  (void)window;

  page = page < 22 ? page + 1 : 0;
  drawPage(page);
}

void up_single_click_handler(ClickRecognizerRef recognizer, Window *window) {
  (void)recognizer;
  (void)window;

  page = page > 0 ? page - 1 : 23;
  drawPage(page);
}


void config_provider(ClickConfig **config, Window *window) {
  (void)window;

  config[BUTTON_ID_SELECT]->click.handler = (ClickHandler) select_single_click_handler;

  config[BUTTON_ID_DOWN]->click.handler = (ClickHandler) down_single_click_handler;
  config[BUTTON_ID_DOWN]->click.repeat_interval_ms = 400;

  config[BUTTON_ID_UP]->click.handler = (ClickHandler) up_single_click_handler;
  config[BUTTON_ID_UP]->click.repeat_interval_ms = 400;
}

void handle_init(AppContextRef ctx) {
  (void)ctx;

  window_init(&window, "Window Name");
  window_stack_push(&window, true /* Animated */);
  window_set_fullscreen(&window, true);
  window_set_background_color(&window, GColorBlack);

  resource_init_current_app(&APP_RESOURCES);

  text_layer_init(&text_layer, window.layer.frame);
  text_layer_set_text_color(&text_layer, GColorWhite);
  text_layer_set_background_color(&text_layer, GColorClear);
  text_layer_set_font(&text_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_9)));
  layer_add_child(&window.layer, &text_layer.layer);

  populateTexts();
  drawPage(page);

  window_set_click_config_provider(&window, (ClickConfigProvider) config_provider);
}

void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init
  };
  app_event_loop(params, &handlers);
}
