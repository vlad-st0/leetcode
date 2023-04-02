from typing import List


class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        i = 0
        while i < len(asteroids) - 1:
            while i < len(asteroids) - 1 and asteroids[i] > 0 and asteroids[i+1] < 0:
                if asteroids[i] > -asteroids[i+1]:
                    asteroids.pop(i+1)
                elif (asteroids[i] < -asteroids[i+1]):
                    asteroids.pop(i)
                    i -= 1 if i > 0 else 0
                else:
                    asteroids.pop(i)
                    asteroids.pop(i)
                    i -= 1 if i > 0 else 0
            i += 1
        return asteroids
