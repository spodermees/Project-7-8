**Risico-iventarisatie**
<table>
<colgroup>
<col style="width: 26%"/>
<col style="width: 13%"/>
<col style="width: 11%"/>
<col style="width: 27%"/>
<col style="width: 21%"/>
</colgroup>
<thead>
<tr class="header">
<th><strong>Risico</strong</th>
<th><strong>Impact (1t/m5)</strong></th>
<th><strong>Kans (1tm/5)</strong></th>
<th><strong>Risicogetal</strong></th>
<th><strong>Hoe te voorkomen?</strong></th>
<th><strong>Maatregel</strong></th>
<th><strong>Kans (na)</strong></th>
<th><strong>Impact (na)</strong></th>
<th><strong>Risicogetal (na)</strong></th>
<th><strong>Oplossing toegepast</strong></th>
</tr>
</thead>
<tbody>
<tr>
<td>Sensoren raken kapot</td>
<td>3</td>
<td>3</td>
<td style="background-color: orange">9</td>
<td>Is niet te voorkomen, maar voorzichting met de spullen omgaan en een goeie omhuising ontwerpen zou het risico moeten verminderen</td>
<td>Netjes omgaan met de spullen, en goed nadenken over een geschikte omhuising</td>
<td>1</td>
<td>3</td>
<td style="background-color:green">3</td>
<td>We hebben een waterdichte omhuising ontworpen en gemaakt. En zijn netjes omgegaan met de spullen</td>
</tr>
<tr>
<td>Mqtt communicatie wilt niet werken</td>
<td>2</td>
<td>4</td>
<td style="background-color: red">8</td>
<td>Er zou iets van een keepalive gehandhaafd worden</td>
<td>Schrijf een keepalive 'functie' zodat de clients constant de broker pingen om te checken dat de connectie nog bestaad</td>
<td>1</td>
<td>4</td>
<td style="background-color: orange">4</td>
<td>Nog niet toegepast</td>
</tr>
<tr>
<td>Vertraging in levering van spullen</td>
<td>3</td>
<td>5</td>
<td style="background-color: red">15</td>
<td>Zorg dat we niet vastlopen zonder sensor/ of zoek een vervangende sensoor waarmee 'vergelijkbare' functionaliteiten getest kunnen worden</td>
<td>Zorg dat er genoeg te doen is (wat er altijd is) zodat het project niet vast komt te liggen</td>
<td>3</td>
<td>3</td>
<td style="background-color: orange">9</td>
<td> nog niet van toepassing</td>
</tr>
<tr>
<td>Test omgeving is niet beschikbaar op RDM</td>
<td>2</td>
<td>2</td>
<td style="background-color: green">4</td>
<td>Niet te voorkomen, wel kan er nagedacht worden of de functionaliteit op een andere manier te testen is</td>
<td>Ver van te voren reserveren/ afspreken met het RDM om te kunnen testen, of kijken of dezelfde functionaliteit ook op een andere manier te testen is</td>
<td>1</td>
<td>2</td>
<td style="background-color: green">2</td>
<td>Er is ver van te voren geboekt om te testen en er is nagedacht over een andere test waar dat mogelijk is</td>
</tr>
<tr>
<td>Data corruptie tijdens of na test(en)</td>
<td>2</td>
<td>4</td>
<td style="background-color: orange">8</td>
<td>Zorg dat er regelmatig back-ups van de data wordt gemaakt</td>
<td>Er worden back-ups gemaakt van de data</td>
<td>1</td>
<td>3</td>
<td style="background-color:green">3</td>
<td>Er worden regelmatig backups gemaakt van de gemete data</td>
</tr>
<tr>
<td>Softwarecrash tijdens test</td>
<td>4</td>
<td>3</td>
<td style="background-color: orange">12</td>
<td>Code opdelen in modules en voorzien van foutafhandeling (try/except), code tijdig testen</td>
<td>Unit tests schrijven, loggen van fouten, watchdog gebruiken</td>
<td>1</td>
<td>3</td>
<td style="background-color: green">3</td>
<td>De belangrijkste code bevat nu try/except en foutmeldingen worden gelogd</td>
</tr>
<tr>
<td>Stroomvoorziening faalt tijdens test</td>
<td>5</td>
<td>2</td>
<td style="background-color: orange">10</td>
<td>Stroomvoorziening goed testen, extra accu meenemen, spanningsval monitoren</td>
<td>Gebruik maken van powerbank of UPS en voeding van tevoren testen</td>
<td>1</td>
<td>2</td>
<td style="background-color: green">2</td>
<td>Powerbank is aangeschaft en wordt gebruikt tijdens tests</td>
</tr>

</tbody>
<!-- changelog -->
<table>
<colgroup>
<col style="width: 11%" />
<col style="width: 17%" />
<col style="width: 71%" />
</colgroup>
<thead>
<tr class="header">
<th><strong>Versie</strong></th>
<th><strong>Datum</strong></th>
<th><strong>Changelog</strong></th>
</tr>
</thead>
<tbody>
<tr>
<td>1</td>
<td>7-3-2025</td>
<td>Risico-inventarisatie is gemaakt/ eerste risico's zijn ingevuld</td>
</tr>
<tr>
<td>2</td>
<td>21-3-2025</td>
<td>nieuwe risico's toegevoegd</td>
</tr>
<tr>
<td>3</td>
<td>27-3-2025</td>
<td>Weer extra risico's toegevoegd</td>
</tr>
<tr>
<td>4</td>
<td>02-06-2025</td>
<td>Na feedback van de 50% opleverset zijn er risico's weg gehaald en toegevoegd</td>
</tr>
</tbody>