class Creature:
    def __init__(self, name, terror_rating):
        self.name = name 
        self.terror_rating = int(terror_rating)
        self.item_ls = []
        self.times = 1
        

    def take(self, item):
        self.item_ls.append(item)
        self.location.item_ls.remove(item)
        self.terror_rating += item.terror_rating


    def drop(self, item):
        self.item_ls.remove(item)
        self.location.item_ls.append(item)
        self.terror_rating -= item.terror_rating


    def get_terror_rating(self):
        return self.terror_rating


    def can_leave(self, direct):
        i = 0
        while i < len(self.location.other_loc):
            if self.location.other_loc[i][0].lower() == direct.lower():
                return self.location.other_loc[i][1]
            i += 1
        return False


    def change_direc(self):
        direct_ls = ['north', 'northeast', 'east', 'southeast', 'south', 'southwest',\
                'west', 'northwest']
        i = 0
        while i < len(direct_ls):
            if self.direct == direct_ls[i]:
                break
            i += 1
        j = i
        i = 0
        while i < 8:
            loc = self.can_leave(direct_ls[j])
            if loc:
                self.direct = direct_ls[j]
                return loc
            j = (j+1) % 8
            i += 1

        
    def goto(self, loc):
        self.location.crea_ls.remove(self)
        self.location = loc
        self.location.crea_ls.append(self)
        self.times = 1
