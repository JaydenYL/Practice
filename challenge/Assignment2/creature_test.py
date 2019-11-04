from creature import Creature
from item import Item
from location import Location

def test_creatures_1():
    crea_1 = Creature('Dog', 10)
    return crea_1.get_terror_rating()

def test_creatures_2():
    crea_2 = Creature('Lost', 2)
    loc_2 = Location('Small tree')
    item_2 = Item('knife', 'a rust knife', 'There is a abandoned knife here.'\
                  , '6' )
    loc_2.item_ls = [item_2]
    crea_2.location = loc_2
    crea_2.take(item_2)
    return crea_2.get_terror_rating()

def test_creatures_3():
    crea_3 = Creature('Lost', 8)
    loc_3 = Location('Big tree')
    item_3 = Item('knife', 'a rust knife', 'There is a abandoned knife here.'\
                  , '6' )
    crea_3.location = loc_3
    crea_3.item_ls = [item_3]
    crea_3.drop(item_3)
    return crea_3.get_terror_rating()

def test_creatures_4():
    crea_4 = Creature('Lost', 2)
    loc_4 = Location('Windmill')
    item_4 = Item('knife', 'a rust knife', 'There is a abandoned knife here.'\
                  , '6' )
    item_5 = Item('coin', 'gold coin', 'This is a treasure.', '-2')
    crea_4.location = loc_4
    loc_4.item_ls = [item_4, item_5]
    crea_4.take(item_4)
    crea_4.take(item_5)
    return crea_4.get_terror_rating()

def test_creatures_5():
    crea_5 = Creature('Lost', 2)
    loc_5 = Location('Garden')
    item_5 = Item('knife', 'a rust knife', 'There is a abandoned knife here.'\
                  , '6' )
    loc_5.item_ls = [item_5]
    crea_5.location = loc_5
    crea_5.take(item_5)
    return len(loc_5.item_ls)
# ===============================================================
#  Create additional test cases here! Don't forget to run them.
# ===============================================================


assert test_creatures_1() == 10, 'Test 1 failed.'
assert test_creatures_2() == 8,  'Test 2 failed.'
assert test_creatures_3() == 2,  'Test 3 failed.'
assert test_creatures_4() == 6,  'Test 4 failed.'
assert test_creatures_5() == 0,  'Test 5 failed.'
