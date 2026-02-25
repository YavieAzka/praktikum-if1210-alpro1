import time
nums = [1, 6, 8, 9, 10, 13]
target = int(input())
mid = int(len(nums))
left = 0
right = len(nums) - 1

while right >= left:
    mid = (right + left)//2
    if target == nums[mid]:
        print(mid)
        break
    elif target < nums[mid]:
        right = mid - 1
    elif target > nums[mid]:
        left = mid + 1
if target < nums[right]: 
    if right == 0:
        print(0)
    else:
        print(right - 1)
elif target > nums[left]:
    print(left + 1)
else:
    print(right + 1)

