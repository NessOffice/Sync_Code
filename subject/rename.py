import os
path = os.listdir('./1.math')
for each in path:
    index = each.find('.')
    new_name = each[index+1:]
    os.rename('./1.math/'+each,'1.math/'+new_name)
