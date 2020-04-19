import sys

from creature import Creature
from item import Item
from location import Location
from preprocessing import process_locations, process_exits,\
                          process_items, process_creatures,\
                          Terminate, Inv, TakeItem, DropItem,\
                          CommandHelp, Look, Flee, IsNearby,\
                          HaveItem, HaveCreature, Honk,\
                          IsDirection
                        
                        
try:
    paths_f, items_f, chasers_f, exits_f = sys.argv[1:5]
    locations = process_locations(paths_f)
    process_items(items_f, locations)
    chasers_ls = process_creatures(chasers_f, locations)
    process_exits(exits_f, locations)
except ValueError:
    print('Usage: python3 game.py <PATHS> <ITEMS> <CHASERS> <EXITS>')
    quit()
except FileNotFoundError:
    print('You have specified an invalid configuration file.')
    quit()

    
if len(chasers_ls) == 0:
    print('There is nothing chasing you!')
    quit()

player = Creature('goose', 5)
player.location = locations[0]
locations[0].crea_ls.append(player)
Look(player.location)
player_turn = True
loc_changed = False


while True:
    if player_turn:
        if loc_changed:
            Look(player.location)
            loc_changed = False
        cmd = input('>> ').upper()
        direct = IsDirection(cmd)
        if cmd == 'QUIT':
            Terminate()
          
        elif cmd == 'HELP':
            CommandHelp()
        
        elif cmd == 'INV':
            Inv(player)
            
        elif cmd.split(' ')[0] == 'TAKE':
            item_name = cmd.split(' ')[1].lower()
            item = HaveItem(item_name, player.location.item_ls)
            if item:
                TakeItem(player, item)
                player_turn = False
            else:
                print('You don\'t see anything like that here.\n')
            
        elif cmd.split(' ')[0] == 'DROP':
            item_name = cmd.split(' ')[1].lower()
            item = HaveItem(item_name, player.item_ls)
            if item:
                DropItem(player, item)
                player_turn = False
            else:
                print('You don\'t have that in your inventory.\n')
                
        elif cmd == 'FLEE':
            Flee(player.location)
                
        elif cmd == 'HONK' or cmd == 'Y':
            Honk(player, chasers_ls)
            player_turn = False

        elif cmd == 'WAIT':
            print('You lie in wait.\n')
            player_turn = False
            
        elif cmd == 'LOOK' or cmd == 'L':
            Look(player.location)
            
        elif cmd.split()[0] == 'LOOK':
            item_name = cmd.split()[1].lower()
            crea = HaveCreature(item_name, player.location.crea_ls)
            if HaveItem(item_name, player.location.item_ls):
                item = HaveItem(item_name, player.location.item_ls)
            else:
                item = HaveItem(item_name, player.item_ls)
            if item:
                print('{} - Terror Rating: {}\n'.format(item.name, item.terror_rating))
            elif item_name == 'me':
                print('You are a goose. You are probably quite terrifying.')
                print('In fact, you have a terror rating of: {}\n'.format(player.terror_rating))
            elif (crea in player.location.crea_ls):
                if (crea.terror_rating - player.terror_rating >= 5):
                    print('{} doesn\'t seem very afraid of you.\n'.format(crea.name))
                elif (player.terror_rating - crea.terror_rating >= 5):
                    print('{} looks a little on-edge around you.\n'.format(crea.name))
                else:
                    print('Hmm. {} is a bit hard to read.\n'.format(crea.name))
            elif item_name == 'here':
                l = len(player.location.item_ls)
                if l == 0:
                    print('There is nothing here.\n')
                else:
                    i = 0
                    while i < l:
                        print('{}| {}'.format(player.location.item_ls[i].short_name.upper().ljust(16)\
                                    , player.location.item_ls[i].name))
                        i += 1
                    print()
            else:
                print('You don\'t see anything like that here.\n')
        
        elif direct:
            loc = player.can_leave(direct)
            if loc :
                print('You move {}, to {}.'.format(direct, loc.name))
                player.goto(loc)
                player_turn = False
                loc_changed = True
            else:
                print('You can\'t go that way.\n')
        
        else:
            print('You can\'t do that.\n')
        
        
    else:
        player_turn = True
        i = 0
        while i < len(chasers_ls):
            # Chaser is at the same location 
            if chasers_ls[i].location.name == player.location.name:
                if loc_changed:
                    print()
                print('{} is trying to catch you!'.format(chasers_ls[i].name))
                if chasers_ls[i].terror_rating >= player.terror_rating or\
                                                chasers_ls[i].times == 2:
                    print('Oh no, you\'ve been caught!\n\
========= GAME OVER =========')
                    quit()
                else:
                    print('But your presence still terrifies them...')
                    if not loc_changed:
                      print()
                    chasers_ls[i].times += 1

            #Chaser is nearby the player
            elif IsNearby(chasers_ls[i], player): 
                chasers_ls[i].goto(player.location)
                if loc_changed:
                    print()
                print('{} has arrived at {}.'.format(chasers_ls[i].name,\
                                                  chasers_ls[i].location.name))
                if not loc_changed:
                    print()


            elif chasers_ls[i].location.item_ls:
                chasers_ls[i].take(chasers_ls[i].location.item_ls[0])

                
            elif chasers_ls[i].location.other_loc:
                loc = chasers_ls[i].change_direc()
                chasers_ls[i].goto(loc)
            i += 1
