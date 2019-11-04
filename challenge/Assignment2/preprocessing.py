from creature import Creature
from item import Item
from location import Location

#----------------------------file_processing functions------------------------

def process_locations(source):
    with open(source, 'r') as f:
        lines = f.readlines()
    loc_ls = []
    i = 0
    while i < len(lines):
        lines[i] = lines[i].strip('\n')
        if lines[i] != '':
            loc_ls.append(lines[i].split(' > '))
        i += 1
        
    if not(loc_ls):
        print('The game cannot run without any rooms :(')
        quit()
    
    loc_name_ls = []
    r_ls = []
    i = 0
    while i < len(loc_ls):
        loc_A, direct, loc_B = loc_ls[i][0].strip(), loc_ls[i][1].lower(), loc_ls[i][2].strip()
        if loc_A in loc_name_ls:
            loc_a = r_ls[loc_name_ls.index(loc_A)]
        else:
            loc_a = Location(loc_A)
            loc_name_ls.append(loc_A)
            r_ls.append(loc_a)
        loc_a.add_other_loc(direct, loc_B)
        
        if not (loc_B in loc_name_ls):
            loc_b = Location(loc_B)
            loc_name_ls.append(loc_B)
            r_ls.append(loc_b)
        i += 1

    i = 0
    while i < len(r_ls):
        j = 0
        while j < len(r_ls[i].other_loc):
            k = 0
            while k < len(r_ls):
                if r_ls[k].name == r_ls[i].other_loc[j][1]:
                    r_ls[i].other_loc[j][1] = r_ls[k]
                    break
                k += 1
            j += 1
        i += 1 
        
    return r_ls


def process_items(source, locations):
    with open(source, 'r') as f:
        lines = f.readlines()
#    print(''.join(i for i in lines))
    i = 0
    while i < len(lines):
        descrip = lines[i].strip()
        if descrip == '':
            i += 1
            continue
        descrip = descrip.split(' | ')
        item = Item(descrip[0], descrip[1], descrip[2].strip(), descrip[3])
        j = 0
        while j < len(locations):
            if locations[j].name == descrip[4]:
                locations[j].item_ls.append(item)
                break
            j += 1
        i += 1
    

def process_creatures(source, locations):
    with open(source, 'r') as f:
        lines = f.readlines()
    if not lines:
        print('There is nothing chasing you!')
        exit()
    r_ls = []
    i = 0
    while i < len(lines):
        info = lines[i].strip().split(' | ')
        chaser = Creature(info[0], info[2])
        chaser.desc = info[1]
        chaser.direct = info[4].lower()
        r_ls.append(chaser)
        j = 0
        while j < len(locations):
            if locations[j].name == info[3]:
                locations[j].crea_ls.append(chaser)
                chaser.location = locations[j]
            j += 1
        i += 1
    return r_ls

def process_exits(source, locations):
    with open(source, 'r') as f:
        lines = f.readlines()
    i = 0
    while i < len(lines):
        exits = lines[i].strip()
        j = 0
        while j < len(locations):
            if locations[j].name == exits:
                locations[j].exits = True
                break
            j += 1
        i += 1
        
#--------------------------------in-game functions----------------------------


def Terminate():
    print('Game terminated.')
    quit()



def Inv(player):
    if player.item_ls:
        print('You, a goose, are carrying the following {}:'.format('item' if\
                                len(player.item_ls) == 1 else 'items'))
        i = 0
        while i < len(player.item_ls):
            print(' - {}'.format(player.item_ls[i].name))
            i += 1
        print()
    else:
        print('You are carrying nothing.\n')



def HaveItem(item_name, item_ls):
    i = 0
    while i < len(item_ls):
        if item_name == item_ls[i].short_name.lower():
            return item_ls[i]
        i += 1
    return False



def HaveCreature(item_name, item_ls):
    i = 0
    while i < len(item_ls):
        if item_name == item_ls[i].name.lower():
            return item_ls[i]
        i += 1
    return False



def TakeItem(creature, item):
    creature.take(item)
    if creature.name == 'goose':
        print('You pick up the {}.\n'.format(item.name))



def DropItem(creature, item):
    creature.drop(item)
    if creature.name == 'goose':
        print('You drop the {}.\n'.format(item.name))



def Flee(cur_loc):
    if cur_loc.exits:
        print('You slip past the dastardly Goosechasers and run off into the \
wilderness! Freedom at last!')
        print('========= F R E E D O M =========')
        quit()
    else:
        print('There\'s nowhere you can run or hide! Find somewhere else to FLEE.\n')



def Honk(player, chasers_ls):
    ls = player.location.crea_ls
    if len(ls) == 1:
        print('All shall quiver before the might of the goose! HONK!\n')
    else:
        print('You sneak up behind your quarry and honk with all the \
force of a really angry airhorn! HONK!')
        i = 0
        while i < len(ls):
            if ls[i].name != 'goose':
                if player.terror_rating > ls[i].terror_rating:
                    print('{} is spooked! They flee immediately!'.format(ls[i].name))
                    chasers_ls.remove(ls[i])
                    player.location.crea_ls.remove(ls[i])
                    if not (chasers_ls):
                        print('\nNone can stand against the power of the goose!')
                        print('========= V I C T O R Y =========')
                        exit()
                    continue
                else:
                    print('{} is not spooked :('.format(ls[i].name))
            i += 1
        print()
        
        

def CommandHelp():
    print('''HELP            - Shows some available commands.
INV             - Lists all the items in your inventory.
TAKE <ITEM>     - Takes an item from your current location.
DROP <ITEM>     - Drops an item at your current location.

LOOK or L       - Lets you see the map/location again.
LOOK <ITEM>     - Lets you see an item in more detail.
LOOK ME         - Sometimes, you just have to admire the feathers.
LOOK <CREATURE> - Sizes up a nearby creature.
LOOK HERE       - Shows a list of all items in the room.

NORTHWEST or NW - Moves you to the northwest.
NORTH or N      - Moves you to the north.
NORTHEAST or NE - Moves you to the northeast.
EAST or E       - Moves you to the east.

SOUTHEAST or SE - Moves you to the southeast.
SOUTH or S      - Moves you to the south.
SOUTHWEST or SW - Moves you to the southwest.
WEST or W       - Moves you to the west.

FLEE            - Attempt to flee from your current location.
HONK or Y       - Attempt to scare off all creatures in the same location.
WAIT            - Do nothing. All other creatures will move around you.
QUIT            - Ends the game. No questions asked.\n''')



def Look(currt_loc):
    ls = currt_loc.other_loc
    map_ls = [['north', 'northeast', 'east', 'southeast', 'south', 'southwest'\
            , 'west', 'northwest'],
            [(1, 5), (1, 7), (2, 7), (3, 7), (3, 5), (3, 3), (2, 3), (1, 3) ],
            [(0, 4), (0, 8), (2, 8), (4, 8), (4, 4), (4, 0), (2, 0), (0, 0) ],
            ['|', '/', '-', '\\', '|', '/', '-', '\\']]

    print_ls = [[' ']*11, [' ']*11,
            [' ',' ',' ',' ','[','x',']',' ',' ',' ',' '],
            [' ']*11, [' ']*11]
    i = 0
    while i < len(ls):
        j = 0
        while j < 8:
            if ls[i][0].lower() == map_ls[0][j]:
                print_ls[map_ls[1][j][0]][map_ls[1][j][1]] = map_ls[3][j]
                y, x= map_ls[2][j][0], map_ls[2][j][1]
                print_ls[y][x : x+3] = '[C]' if ls[i][1].crea_ls else '[ ]'
                break
            j += 1
        i += 1

    i = 0
    while i < 5:
        s = ''
        j = 0
        while j < 11:
            s += print_ls[i][j]
            j += 1
        print(s.rstrip())
        i += 1
        
    print('You are now at: {}.'.format(currt_loc.name))
    if (not currt_loc.item_ls) and (len(currt_loc.crea_ls) == 1):
        print('There is nothing here.')
    else:
        s = ''
        i = 0
        while i < len(currt_loc.item_ls):
            s += '{}{}'.format(currt_loc.item_ls[i].full_desc.strip(), ' '\
                                  if i != len(currt_loc.item_ls) - 1 else '')
            i += 1
        i = 0
        while i < len(currt_loc.crea_ls):
            if i == 0 and s:
                s += ' '
            if currt_loc.crea_ls[i].name != 'goose':
                s += '{}{}'.format(currt_loc.crea_ls[i].desc.strip(), ' '\
                                   if i != len(currt_loc.crea_ls) - 1 else '')
            i += 1
        print(s.strip())
    if currt_loc.exits:
        print('The path to freedom is clear. You can FLEE this place.\n')
    else:
        print()
    


def IsNearby(chaser, player):
    i = 0
    while i < len(chaser.location.other_loc):
        if player.location.name == chaser.location.other_loc[i][1].name:
            return True
        i += 1
    return False



def IsDirection(cmd):
    drc_ls = [['NORTH', 'NORTHEAST','EAST', 'SOUTHEAST', 'SOUTH', 'SOUTHWEST'\
            ,'WEST','NORTHWEST'],['N', 'NE', 'E', 'SE', 'S', 'SW', 'W', 'NW']]
    i = 0
    while i < 8:
        if cmd == drc_ls[0][i] or cmd == drc_ls[1][i]:
            return drc_ls[0][i].lower()
        i += 1
    return False
