# Robuustheids Analyse

## Inleiding

"Autonoom Manoeuvreren In De Haven" is een project opgestart door Geert Mosterdijk, mede-eigenaar van het bedrijf Sens2Sea. Zij zijn gespecialiseerd in maritieme radar- en meetsystemen en hebben de wens om Schepen autonoom te laten aanmeren in de haven. Zij zien dit voor zich door een systeem te maken voor op schepen waarbij er verschillende sensor- en aandrijfmodules zijn, deze werken vervolgens nauw samen om ervoor te zorgen dat de aandrijfmodules het schip autonoom naar de kade kunnen voortbewegen.
Uit dit project is een prototype ontstaan die ontworpen is aan de hand van verschillende requirements. Om te kijken hoe dit prototype besrand is tegen verschillende risico's is deze analyse gemaakt. Ook maakt het duidelijk om welke manier er mee om is gegaan om te zorgen dat er geen of minder gevolgen zijn mochten er onverwachte dingen gebeuren


| Probleem                     | Wanneer treedt het op?                                                                 | Getroffen maatregelen                                                                                     | Heeft dat geholpen? |
|-----------------------------|-----------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------|---------------------|
| Ongeldige sensordata        | De radar sensor geeft een waarde die niet overeenkomt met de werkelijke afstand tot de kade | In de code is een failsafe ingebouwd die de data eerst valideert, ongeldige/onverwachte data wordt niet gebruikt | ja                  |
| Losse connectors            | Door eventuele trilling of schommeling op het schip kunnen connectors los laten, hierdoor kan communicatie verstoord worden | Kabels kunnen worden vastgemaakt met lijm                                                                 | ja                  |
| Waterinfiltratie            | Wanneer er vocht in de behuizing komt kan er kortsluiting of corrosie ontstaan          | geen                                                                                                       | nee                 |
| MQTT verbinding verbroken   | De verbinding met de MQTT broker is verbroken en er kan niet meer gecommuniceerd worden | De “main” programma zal opnieuw proberen verbinding te maken met de broker                                 | ja                  |
| Componenten los in de behuizing | De onderdelen zijn niet goed vast gemaakt in de behuizing, hierdoor kan bijvoorbeeld de radar de verkeerde kant op kijken | Alle onderdelen zijn met schroeven aan de behuizing vastgemaakt                                            | ja                  |

## Changelog

|Versie|Datum|Beschrijving|
|---|---|---|
|1|04-04-2025|Eerst versie opgezet|
|2|08-05-2025|Enkele problemen toegevoegd en verder uitgewerkt|
|3|5-06-2025|Behuizing problemen toegevoegd|
|4|8-07-2025|Document overgezet naar Markdown voor betere consistentie|
