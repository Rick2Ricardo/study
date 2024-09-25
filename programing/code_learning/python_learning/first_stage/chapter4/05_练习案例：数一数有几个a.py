"""
数一数有几个a
"""
name = "itheima is a brand of itcast"

count = 0
for x in name:
    if x == 'a':
        count += 1
print(f"{name}中共含有{count}个字母a")
