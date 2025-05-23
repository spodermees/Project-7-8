# Aantekeningen
## eerste vragen

Vragen PO

Vragen ronde 1:

SDI: Moet er continu data worden gestuurd of alleen op aanvraag? (aan/uit knop)-
event driven op afstand aan en uit
Wordt het een netwerk via ethernet?
ga uit van MQTT via ethernet kabel
Hoe moet de behuizing er uit komen zien?
Waterdicht (kijk naar ze dat met en auto doen)
Naar waar moet de broker de data sturen?- naar een applicatie die ergens draait.
Wat kan de zelfgemaakte microcontroller allemaal?
Moet er een dashboard komen om de modules uit te lezen
Een kleine interface is goed maar geen vereiste, via lcd scherm.


## begin gesprek
wat is het probleem
Autonoom varen staat in de kinderschoenen, veel bedrijven zijn er mee bezig
Zijn pogingen gedaan om monsters van het water te nemen

Zijn veel problemen met aanleggen en weggevaren zekers met golven en (harde) winden (bij een ander schip)
EVAP experimenteel varend … platform
Dit is een estafette project
Als je een haven maakt zijn er nog problemen als je een zuiger hebt, daar is een bak die elke keer die moet vervangen worden

PK marine is een samenwerking waar wij niet afhankelijk van zijn
SDI staat voor standarised distrubuted intel
Eerst nadenken over het hoofdprobleem, dus niet nog niet beginnen met hard- en software

Eerst een keertje langs voor SDI uitleg en meename
Zoveel mogelijke scheiden van elkaar

Zo veel mogelijke universaile manieren van meten en uitschrijven

Ze willen eigenlijk heel onafhankelijk van 1 leverancier dus alles beetje open source

Eerste afspraak donderdag komen naar RDM lopen we klem dan vaker komen zoals op de vrijdag of woensdag

### SDI


### Wat is SDI

SDI (Standerdized distributed intelegence) is een gestandaardiseerde manier hoe componenten met elklaar communiceren. Dit helpt om functionaliteiten te integreren. Om dit te doen gebruik je decompositie. En deze verschillende functionaliteiten stop je in een bibliotheek die je kan hergebruiken. 

#### Decompsitie
Decompositie is het klein maken van grote complexen problemen. Dit doe je door functionele 

Je begint met het project met het nadenken wat zijn de verschillende onderdelen van het probleem
Dit is ook een begin van een verslag
Deze benadering van problemen wordt ook wel functionele decompositie
Tip maak je probleem juist zo groot mogelijk, dit kan helpen om er achter te komen wat er echt relevant is
Je moet inzoomen naar wat belangrijk is en alles wat je niet doet mag je aannames van maken dat het allemaal goed komt

 
SDI module die communceerd met mqtt. Deze module is voor een sensor. Deze sensor is .... (onderzoek) 


## gesprek 2
Blokschema (functionele decompositie) > breng het grote probleem in kaart dmv opdelen in kleine problemen.

Begin bij alle relevante blokken
Denk aan alle personen die nodig zouden zijn om het probleem op te lossen, wat zou die taak zijn. Kan dat niet > niet functioneel
Bedenk wat er in en uit een blok gaat (mqtt), houd het functioneel. Bij ELKE data hoort ook metadata zoals tijdstip etc.
Ook alles wat invloed heeft op het schip moet er in, ook de omgeving dus > denk aan andere schepen of de rivier

Voorbeeld schip:
Mobility – Recources – Support – Payload
Mobility: alles wat het schip bewegend houdt
Recourses: alles wat het schip in leven houdt
Payload: Waar is het schip voor gemaakt is (passagiers, vracht, wapens)
Verdeel deze weer verder onder, bv mobilty > vooruit, opzij, rollen
Kijk alleen naar welke voor jou relevant is wanneer je eraan gaat werken, schuif de andere aan de kant.
Het biedt een houvast hoe je een verslag erover zou schrijven, elk blok een paragraaf bv
Elke module in SDI heeft desired en undesired in en outputs, het beste zou zijn alle undesired inputs te herkennen en daar failsaves voor te maken, zo voorkom je undesired outputs.

