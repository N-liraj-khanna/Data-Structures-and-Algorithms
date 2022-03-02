# Calculate the min_angle and the hour_angle first
# then find all the possible angles which is three in total
# then the minimum is the min angle required
# TC => O(1) SC => O(1)
class Solution:
    def angleClock(self, h: int, m: int) -> float:
        hour_angle = (h*30+(m/2)) % 360
        min_angle = (m/5)*30

        angle1 = hour_angle+360-min_angle
        angle2 = min_angle+360-hour_angle
        angle3 = abs(hour_angle-min_angle)

        return min(angle1, angle2, angle3)
