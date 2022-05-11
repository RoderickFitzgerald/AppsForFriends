stringA = "Killdakka Warband (Orks), Shieldbreaker (Marines), Eldritch Omens x2 (Chaos & Eldar), Lynx (Eldar), Hornet x2 (Eldar), Wraithknight x3 (Eldar), Wolves combat patrol, Eldar combat patrol, Skitarii (AdMech), Chaos Marines (about half done), Meganobz (Orks), Boyz (Orks), Primaris Rievers (Marines), Maugen Ra (Eldar), Guardians (Eldar), Dark Reapers (Eldar), Venerable Dreadnought (Marines), ThunderCav (Marines), Chaos Bikers"
stringB = stringA.split(',')
c = 1
for a in stringB:
    c = c + 1
    print(str(c) + '.')
    #print(a)
    #print("\n")