bd_district_info = {}
bd_district_info["Barguna"] = {"division": "Barisal", "established": 1984, "population": 892, "area": 1939}
bd_district_info["Barisal"] = {"division": "Barisal", "established": 1797, "population": 2415, "area": 2785}
bd_district_info["Bhola"] = {"division": "Barisal", "established": 1984, "population": 1946, "area": 3403}
bd_district_info["Jhalkati"] = {"division": "Barisal", "established": 1984, "population": 710, "area": 749}
bd_district_info["Patuakhali"] = {"division": "Barisal", "established": 1969, "population": 1596, "area": 3221}
bd_district_info["Pirojput"] = {"division": "Barisal", "established": 1984, "population": 1277, "area": 1308}

item = input("Please enter a district name : ")
#print(bd_district_info[item])
print("District =", item, "\nDivision =", bd_district_info[item]["division"],"\nEstablished =", bd_district_info[item]["established"],"\nPopulation (thousands) =", bd_district_info[item]["population"], "\nArea (km^2) =", bd_district_info[item]["area"])
