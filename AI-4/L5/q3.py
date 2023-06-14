from UCS import UniformCostSearch

def main():
        graph = {
                'Dunwich': [('Blaxhall', 17)],
                'Blaxhall': [('Dunwich', 15)],
                'Harwich': [('Dunwich', 53), ('Blaxhall', 40), ('Tiptree', 31)],
                'Feering': [('Blaxhall', 46), ('Maldon', 11)],
                'Tiptree': [('Feering', 3), ('Clacton', 29)],
                'Clacton': [('Harwich', 17), ('Maldon', 40)],
                'Maldon': [('Tiptree', 8)]
        }

        print('Distance form Harwich to Mandol: ', end='')
        print(UniformCostSearch(graph).search('Harwich', 'Maldon'))

if __name__ =='__main__':
    main()