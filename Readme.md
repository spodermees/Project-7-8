# Autonoom Manoeuvreren In De Haven

## Inhoudsopgave

- Beschrijving
- Werking
- Installatie
- Belangrijke documenten & navigatie
- Contributers

## Beschrijving

Project 7/8 staat helemaal in het teken van autonoom manouvreren, of in ieder geval dit project van Project 7/8. Samen met Sens2Sea en Geet mosterdijk, wordt er gekeken naar hoe het aanmeren en wegvaren veiliger en efficiënter kan door behulp van verschillende sensoren en actuatoren. Op dit moment zijn de enige toepassingen hiervan niet open source, en lastig en duur te onderhouden. In dit project wordt er onderzoek gedaan naar verschillende sensoren en het gewenste communicatie protocool: "MQTT" in combinatie met SDI. De scope van dit project is gericht op de sensoren niet actuatoren, dat is voor een vervolg project hier van. Voor een volledige uitleg en demo kunt u de [demovideo](./demovideo.mp4) kijken


## Werking

Het prototype bestaat uit meerdere elektronische onderdelen en en een behuizing, hier volgt een beschrijving van wat elk onderdeel precies doet en waarom er voor deze gekozen is. In de [architectuurontwerp](documentatie/diagrammen/Architectuur.png) en de [interne architectuurontwerp](documentatie/diagrammen/InterneArchitectuur.png) is visueel gemaakt hoe de onderdelen verbonden zijn.

#### Microcontroller 
In dit project was er een controller nodig die het prototype aanstuurt. Zo wordt deze gebruikt voor het ophalen van de afstand van de radarsensor om deze vervolgens door te sturen naar het lcd scherm en de MQTT broker. Er is gekozen voor een Raspberry PI 5 omdat de ondersteuning met de Radar sensor hier het beste mee is en omdat deze het meest robuust is in een omgeving zoals op een schip

#### Radar
Het onderdeel wat de binnen het prototype de afstand meet is de XM125 evaluation board met daarop de A121 radar sensor. Waarom er voor deze is gekozen is terug te lezen in het [sensor onderzoek](./documentatie/onderzoek/eigenonderzoek/Sensoronderzoek/Sensoronderzoek.md)

#### LCD scherm
Om de data real-time te laten zien aan mensen die met de module aan het werk zijn is er een LCD scherm ingebouwd, deze laat de exacte afstand zien die de radar meet.

#### MQTT
Om het hele project te laten voldoen aan de standaarden zoals beschreven in de [SDI docs](./documentatie/projectdocumentatie/SDIdocs) is er onderzoek gedaan naar [MQTT](./documentatie/onderzoek/eigenonderzoek/MQTTonderzoek/MQTT_research.pdf). Hieruit is gebleken waarom MQTT een passende oplossing is om te gebruiken binnen dit project. De microcontroller stuurt alle data door naar de MQTT broker zodat hiermee vervolgens kan worden gerekend om het schip autonoom te laten aanmeren


## Installatie

Voor dit project zijn verschillende dingen nodig om de testopstelling na te beleven. Deze vind je in [handleiding](documentatie/projectdocumentatie/handleiding.md).



## Belangrijke documentatie & navigatie

Er zijn voor dit project wat belangrijke documenten gemaakt/ onderzoeken uitgevoerd, hieronder staan ze op een lijstje en waar ze te vinden zijn.

- Onderzoeken, in dit project onderzoeken gedaan naar sensoren en communicatie protocollen die zijn allemaal in dit mapje te vinden.

>Met terminal: cd documentatie\onderzoek\eigenonderzoek
>Zonder terminal: documentatie -> onderzoek -> eigenonderzoek

- Projectdocumentatie, hier is alle documentatie te vinden die de projectdoelen aantonen zoals risico-inventarisatie en Stakeholder-analyse. In de [handleiding](documentatie/projectdocumentatie/handleiding.md) is er ook nog dieper ingegaan op hoe je het systeem in elkaar zet.

>Met Terminal cd documentatie\projectdocumentatie
>Zonder Terminal documentatie- > projectdocumentatie

- Code, hier is de code te vinden die wordt gebruikt voor het eindproduct

>Met Terminal: `cd software/raspberrypi/project/py`
>Zonder Terminal [code](./software/raspberrypi/project.py)

Om de broker te runnen kun je naar [broker](./software/broker/docker-compose.yml). of `cd software/broker/`. Je kunt de broker aanzetten als je docker hebt met het command `docker-compose up -d --build` en uitzetten met `docker compose down`.

De gebruikersnaam van de broker is `Hidde` en het wachtwoord is `3332ks`

## Contributors

- Hwayda Bashair (1049850)
- Hidde Gerritsen (1079142)
- Olaf Goudriaan (1071349)
- Mees van der Waal (1052159)

# TODO
- TODO weghalen
- documentatie
    - Testrapport (Hwayda?)
    - burndown chart /
    - flowchart
    - jira bijwerken
    - sensor onderzoek -> verander ook de verwijzing in Readme.md onder het kopje Radar

individueel
- reflectie (Hidde check)
