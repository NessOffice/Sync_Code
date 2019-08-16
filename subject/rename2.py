import os
path = os.listdir('./1.math')
index = 1
for each in path:
    new_name = str(index) + '.' + each
    os.rename('./1.math/'+each,'1.math/'+new_name)
    index += 1
