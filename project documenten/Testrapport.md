# Testrapport

## Inleiding

Dit testrapport beschrijft de testprocedures en resultaten met betrekking tot project 7-8. Binnen dit project zijn diverse onderdelen ontwikkeld die aan specifieke kwaliteits- en functionele eisen moeten voldoen. Om de betrouwbaarheid, functionaliteit en prestaties van deze onderdelen te waarborgen, zijn uitgebreide tests uitgevoerd.

In dit rapport worden de gehanteerde testmethoden, de uitgevoerde testscenario’s en de verkregen resultaten gedocumenteerd. Op basis van deze bevindingen worden conclusies getrokken en, waar nodig, aanbevelingen gedaan voor verbeteringen.

## Testen

### Test 1 Afstandsmeting met de sensoor

Deze test valideert of de Acconeer XM125 radarsensor nauwkeurig afstand kan meten tot een object. Door een bekend object langzaam van de sensor weg te bewegen, vergelijken we de gemeten waarden van de sensor met handmatige observaties. Dit vormt de basis voor betrouwbare afstandsmetingen in een maritieme context. De resultaten helpen om in te schatten of de sensor geschikt is voor het bepalen van de afstand tot een kade. [1.1]

#### Benodigdheden

- SparkFun Pulsed Coherent Radar Sensor - Acconeer XM125 (Qwiic)
- Test code (voeg naam van juiste bestand later nog toe)
- Een object dat bewogen kan worden
- Console/ serial monitor om de sensor readings af te lezen

#### Testopstelling

- Monteer de radarsensoor op een vaste plek
- Verbind de sensor met de pi
- Zorg dat de pi de juiste code erop heeft
- Beweeg het object langzaam naar achteren toe en noteer de metingen

#### Acceptatie-criteria

- De sensoor leest de afstand van objec op 1cm nauwkeurig
- De sensoor herkent het object op 20 meter afstand

#### Waarnemingen

|Test | Gemeten waarde door sensor| Gemeten waarde door mens |
|---|---|--|
| 1 | | |
| 2 | | |
| 3 | | |
| 4 | | |
| 5 | | |

#### Conclusie

## Changelog

| Versie | Datum       | Wijzigingen                                     |
|--------|------------|--------------------------------------------------|
| 1    | 21-03-2025 | Eerste versie van het testrapport opgesteld      |
| 2 | 04-04-2025 | Eerste testen toegevoegd |
