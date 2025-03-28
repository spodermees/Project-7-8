# Robuustheidsanalyse

## Probleemstelling

Voor dit project wordt er een sensoor "ontwikkeld" die op een boot komt te staan, dit neemt een aantal "risico's" met zich mee waaronder risico's voor de robuustheid van het prototype.

## Software

| Probleem   | Wanneer treedt het op | Wat is er aan gedaan | Heeft het geholpen |
|-------------|--------| ------| ---- |
| Verkeerde wordt afgelezen en opgestuurt      | Als de sensoor verkeerd de waarde afleest, door niet juiste calibratie | Er is onderzoek naar de bundelgroote gedaan, en er is gekozen voor een zo klein mogelijke bundel |  |
| Mqtt valt uit   | Als de verbinding wordt verbroken | Er zit een callback functie in de code, en een logger | Het heeft geholpen met connectie stabieler maken |

## Hardware

| Probleem | Wanneer treedt het op | Wat is er aan gedaan | Heeft het geholpen|
|----|----|----|----|
| Er kan water in de behuizing komen| Wanneer er een opening is in de behuizing | Kies voor een materiaal en "dichtmaakmethode" die waterdicht is | Er komt vele male minder tot geen water bij de sensor |
| Draadje schiet los | Wanneer er veel kracht aan het onderdeel wordt uitgeoefend | Draadjes extra vast maken | De draadjes komen minder snel los |

## Changelog

| Versie | Datum | Wat is er veranderd |
|-| --- | ---------------- |
| 1 | 28-03-2025  | Eerste opzet gemaakt en eerste items toegevoegd |
