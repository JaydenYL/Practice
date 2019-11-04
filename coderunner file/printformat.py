a = b = c = d = e = int(7)
print('Average of { %.2f, %.2f, %.2f }'%(a, b, c))
from string import Template

t = Template('Average of {$A,$B,$C} ')
t = t.substitute(A=a, B=b, C=c)
#print(t)
print('Average of {{ {:.2f}, {:.2f}, {:.2f} }}'.format(a, b, c))