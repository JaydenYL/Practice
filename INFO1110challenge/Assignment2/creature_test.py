from creature import Creature
from item import Item
from location import Location

# Test whether the 'get_terror_rating' method can function correctly
def test_creatures_1():
    crea_1 = Creature('Dog', 10)
    return crea_1.get_terror_rating()

  
# Test the 'take' mothod
def test_creatures_2():
    crea_2 = Creature('Lost', 2)
    loc_2 = Location('Small tree')
    item_2 = Item('knife', 'a rust knife', 'There is a abandoned knife here.'\
                  , '6' )
    loc_2.item_ls = [item_2]
    crea_2.location = loc_2
    crea_2.take(item_2)
    return len(loc_2.item_ls) # return 0, because there is no item

  
# Test the comnbination of 'take' and 'drop' method
def test_creatures_3():
    crea_3 = Creature('Lost', 8)
    loc_3 = Location('Big tree')
    item_3 = Item('knife', 'a rust knife', 'There is a abandoned knife here.'\
                  , '6' )
    crea_3.location = loc_3
    loc_3.item_ls = [item_3]
    crea_3.take(item_3)
    x = crea_3.get_terror_rating()
    crea_3.drop(item_3)
    y = crea_3.get_terror_rating()
    return (x, y) #return (14, 8), because terror_rating becomes 14 after it 
                  #takes item_3 , and comes back to 8 after droping the item_3

# Test double 'take'
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
  
# Test 'take' while there is an item 
def test_creatures_5():
    crea_5 = Creature('Lost', 2)
    loc_5 = Location('Garden')
    item_5 = Item('knife', 'a rust knife', 'There is a abandoned knife here.'\
                  , '6' )
    loc_5.item_ls = [item_5]
    crea_5.location = loc_5
    crea_5.take(item_5)
    return len(loc_5.item_ls)


assert test_creatures_1() == 10, 'Test 1 failed.'
assert test_creatures_2() == 0,  'Test 2 failed.'
assert test_creatures_3() == (14, 8),  'Test 3 failed.'
assert test_creatures_4() == 6,  'Test 4 failed.'
assert test_creatures_5() == 0,  'Test 5 failed.'
