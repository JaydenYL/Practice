class Item:
    def __init__(self, short_name, item_name, full_desc, terror_rating):
        self.short_name = short_name
        self.name = item_name
        self.full_desc = full_desc
        self.terror_rating = int(terror_rating)
