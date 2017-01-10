T = int(raw_input())

for t in range(T):
    
    max_probability = 0

    H, S = map(int, raw_input().split())
    dices = raw_input().split()

    for dice in dices:
        is_negative = (dice.find('-') != -1)
        has_z = (dice.find('+') != -1) or (dice.find('-') != -1)

        dice = dice.replace('+', ' ')
        dice = dice.replace('-', ' ')
        dice = dice.replace('d', ' ')

        X = 0
        Y = 0
        Z = 0

        if has_z:
            X, Y, Z = map(int, dice.split())

            if is_negative:
                Z = Z * -1

        else:
            X, Y = map(int, dice.split())

        MAX_SUM = X * Y + 1

        count = [[0] * MAX_SUM for _ in range(X + 1)]
        count[0][0] = 1

        for x in range(X):
            for i in range(MAX_SUM):
                for y in range(Y):
                    if (i + y + 1) < MAX_SUM:
                        count[x + 1][i + y + 1] += count[x][i];

        over_count = 0
        total_count = 0
        
        for i in range(MAX_SUM):
          total_count += count[X][i];
          if ((i + Z) >= H):
              over_count += count[X][i];


        probability = over_count / (float)(total_count);
        max_probability = max(probability, max_probability);
    
    print('Case #%d: %.6f' % (t + 1, max_probability))
