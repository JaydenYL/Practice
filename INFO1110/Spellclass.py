class Spell:
	
	def __init__(self, name, school, level, a, effect):
		self.name = name
		self.school = school
		self.level = level
		self.cast_limit = a
		self.effect = effect
		if level < 0 or level > 9:
			raise ValueError
		self.casts = a
		
	def cast(self):
		if self.casts <= 0:
			print('Can\' cast {} any more today'.format(self.name))
			return
		print('Casting \'Summon Cat\'...\n{}\n\nYou can cast {} more times today\n{}'.format(self.effect, self.casts - 1, '-'*50))
		self.casts -= 1
		
	def recharge(self):
		self.casts = self.cast_limit
	
	def get_name(self):
		return self.name


class Spellbook:
	
	def __init__(self, a, b):
		self.material = a
		self.capacity = int(b)
		self.spell_ls = []
		
	def add_spell(self, spell):
		s = 0 
		i = 0
		while i < len(self.spell_ls):
			s += self.spell_ls[i].level
			i += 1
		s += spell.level
		if s > self.capacity:
			raise ValueError('We are nearing the end of our power level. You cannot write {} into this spellbook.'.format(spell.name))
		self.spell_ls.append(spell)
		
	def cast_spell(self, s):
		i = 0
		while i < len(self.spell_ls):
			if self.spell_ls[i] == s:
				s.cast()
				return
			i += 1
		print('There is no spell called {} here'.format(s))

	def cast_strongest(self):
		max = 0
		i = 0
		while i < len(self.spell_ls):
			if max <= self.spell_ls[i].level:
				max = self.spell_ls[i].level
				r_spell = self.spell_ls[i]
			i += 1
			
		return r_spell
		
	def cast_all(self):
		i = 0
		while i < len(self.spell_ls):
			if self.spell_ls[i].casts > 0:
				self.spell_ls[i].cast()
			i += 1
			
	def refresh_all(self):
		i = 0
		while i < len(self.spell_ls):
			self.spell_ls[i].recharge()
			i += 1


if __name__ == '__main__':
	
	cat_summoned = "You reach into your pocket for a can of tuna and crack it open. A cat pops into existence beside you in a puff of smoke!"
	summon = Spell("Summon Cat", "Conjuration", 1, 4, cat_summoned) 
	summon.cast()
	
	cat_effects = "You throw a bag of catnip at a nearby, unfortunate soul, and a giant catcomes crashing down on them from the heavens above!"
	cataclysm = Spell("Cataclysm", "Conjuration", 6, 2, cat_effects)
	
	print('-'*50)
	
	ratty_textbook = Spellbook("Paper", "5")
	try:
		ratty_textbook.add_spell(cataclysm) # Recall: cataclysm.get_level() == 6
	except ValueError as e:
		print(e)
		
	tablet = Spellbook('Stone', 24)
	post_it_note = Spellbook('Paper', 3)
	
	tickle = Spell('Tickle', 'Evocation', 0, 100, "You point at a target and watch them squirm as an invisible feather begins tickling at their sides! Or not. Some people aren't ticklish.")
	castle = Spell("Queen Elsa's Instant Castle", 'Transmutation', 8, 1, "You sing a showstopping Broadway tune and build an ice castle out of basically nothing. That feels pretty great.")
	cheesecake = Spell("Cheesecake Calamity", 'Conjuration', 8, 5, "You mutter a few words and a slice of cheesecake spontaneously appears on a point that you can see within range. Then two slices. Then four. Then eight. Sixteen. Thirty-two. Oh no...")
	anti_cheesecake = Spell("Destroy Cheesecake", 'Evocation', 7, 3, "For the next five minutes, any continuous segment of cheesecake you touch immediately disintegrates. It tastes lovely.")
	f_ball = Spell("Fireball", 'Evocation', 3, 3, "You crush a bit of charcoal between your fingers and specify a point within 120 feet. An explosion of heat and light (and smoke!) expands from that point, and it's just SO PRETTY.")
	
	post_it_note.add_spell(tickle) 
	post_it_note.add_spell(f_ball)
	
	try:
		post_it_note.add_spell(cheesecake) 
	except ValueError as e:
		print(e)		
	
	post_it_note.cast_spell("Destroy Cheesecake") 
	post_it_note.cast_spell("Fireball") 
	post_it_note.cast_all()
	tablet.add_spell(summon) 
	tablet.add_spell(cheesecake) 
	tablet.add_spell(castle) 
	tablet.add_spell(anti_cheesecake) 
	tablet.cast_strongest() 
	tablet.cast_strongest() 
	tablet.cast_all() 
	tablet.refresh_all()