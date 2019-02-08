# Author: btjanaka (Bryon Tjanaka)
# Problem: (UVa) 787
while True:
    try:
        line = input()
    except:
        break

    nums = list(map(int, line.split()[:-1]))

    mx = nums[0]
    for i in range(len(nums)):
        for j in range(i, len(nums)):
            prod = 1
            for k in range(i, j + 1):
                prod *= nums[k]
            if prod > mx: mx = prod

    print(mx)
