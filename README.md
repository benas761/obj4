# obj4

std::string konteinerio, o taip pat ir asociatyvių konteinerių naudojimas

Paleidimo instrukcija:
- Ant windows: atidarykite norimą .cpp failą su codeblocks arba kitu IDE ir paleiskite programą.
- Ant unix: nueikite į norimos programos katalogą ir įrašykite `g++ -o main main.cpp` ir `./main`.

Programa buvo rašyta naudojant 2 konteinerius: std::vector ir std::map. Laikai:

|Užduotis|Tipas|Laikas|
|:-:|:-:|:-:|
|1|std::vector|0.138s|
|1|std::map|0.061s|
|2|std::vector|0.154s|
|2|std::map|0.078s|
|3|std::vector|0.185s|
|3|std::map|0.201s|

1, 2 užduočių aprašymas:
- in() funkcija nuskaito duomenis iš failo, imdama tik raides ir tarpus, bei paverčianti didžiasias raides mažosiomis.
- read() funkcija duomenis perduoda std::vector arba std::map. Prieš perdavimą dar yra patikrinama ar toks žodis jau egzistuoja nuskaitytų žodžių sąraše ir jei taip - tiesiog priskaičiuoja 1 (bei 2 programoje perduoda eilutę), o jei ne - prideda naują žodį.
- merge() jei reikia, ištrina besikartojančias eilutes ir nesikartojančius žodžius.
- out() išveda duomenis formatu žodis, pasikartojimų kiekis ir visos eilutės, kuriose tas žodis pasirodo (keikviena eilutė naujame stulpelyje).

3 užduoties aprašymas:
- Perskaitomi duomenis iš failo, panaikinant " ir ' darbui su HTML (sunku nepaslėptus link'us rasti).
- Jei žodis turi `http` arba `www`, tai jis išsaugomas kaip link'as.
- Link'ai išvedami į failą.
