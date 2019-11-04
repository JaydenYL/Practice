class Location:
    def __init__(self, name):
        self.name = name
        self.item_ls = []
        self.crea_ls = []
        self.other_loc = []
        self.exits = False
        
    def add_item(self, item):
        self.item_ls.append(item)

    def remove_item(self, item):
        self.item_ls.remove(item)
    
    def add_other_loc(self, direction, location):
        self.other_loc.append([direction, location])
