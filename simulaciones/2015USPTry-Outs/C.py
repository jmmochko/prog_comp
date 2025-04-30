import math

def solve():
    T = int(input())
    input_lines = [input().split(" ") for i in range(T)]
    for line in input_lines[0:T]:
        alpha = float(line[0])
        l = float(line[1])
        n = int(line[2])
       
        if n == 0:
            print("0 0")
            continue
       
        theta_rad = math.radians(alpha)
       
        if alpha == 0:
            x = n * l
            y = 0.0
        else:
            numerator = 1 - math.cos(n * theta_rad) - 1j * math.sin(n * theta_rad)
            denominator = 1 - math.cos(theta_rad) - 1j * math.sin(theta_rad)
            if denominator == 0:
                x = n * l
                y = 0.0
            else:
                S = l * numerator / denominator
                x = S.real
                y = -S.imag  

        print("{0:.8f} {1:.8f}".format(x, -y))

if __name__ == "__main__":
    solve()