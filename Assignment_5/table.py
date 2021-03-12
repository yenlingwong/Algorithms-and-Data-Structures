import matplotlib.pyplot as plt
import pandas as pd

if __name__ == '__main__':
    data = []
    n = [0, 5, 10, 15, 20, 25, 30, 35, 40, 45]
    result1 = []
    naive_recursive = []
    result2 = []
    bottom_up = []
    result3 = []
    closed_form = []
    result4 = []
    matrix_multiplication = []
    with open('output.txt', 'r') as input:
        for line in input:
            info = line.rstrip().split()
            result1.append(int(info[1]))
            
            naive_recursive.append(float(info[2]))
            result2.append(int(info[3]))
            bottom_up.append(float(info[4]))
            result3.append(int(info[5]))
            
            closed_form.append(float(info[6]))
            result4.append(int(info[7]))
            matrix_multiplication.append(float(info[8]))

    
    for i in range(10):
        data.append([n[i], result1[i], naive_recursive[i], result2[i], bottom_up[i], result3[i], closed_form[i], result4[i], matrix_multiplication[i]])

    fig, ax = plt.subplots()

    fig.patch.set_visible(False)
    ax.axis('off')
    ax.axis('tight')

    colLabels = ['n', 'Result1', 'Naive Recursive', 'Result2', 'Bottom Up', 'Result3', 'Closed Form', 'Result4', 'Matrix Multiplication']
    df = pd.DataFrame(data, columns=colLabels)

    ax.table(
        cellText=df.values,
        colLabels=df.columns,
        cellLoc='center',
        loc='center'
    )

    fig.tight_layout()

    plt.savefig('Table.png', bbox_inches='tight', pad_inches=0.05, 
                dpi=1000)