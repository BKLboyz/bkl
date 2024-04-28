class hashTable:
    def __init__(self):
        self.size = 10
        self.table = [None] * self.size
        self.elementCount = 0
        self.comparisons = 0

    def isFull(self):
        return self.elementCount == self.size

    def hashFunction(self, element):
        return element % self.size

    def insert(self, record):
        if self.isFull():
            print("Hash Table Full")
            return False

        position = self.hashFunction(record.get_number())

        if self.table[position] is None:
            self.table[position] = record
            print("Phone number of " + record.get_name() + " is at position " + str(position))
            self.elementCount += 1
            return True

        else:
            print("Collision has occurred for " + record.get_name() + "'s phone number at position " + str(position) + ". Finding new Position.")
            while self.table[position] is not None:
                position += 1
                if position >= self.size:
                    position = 0

            self.table[position] = record
            print("Phone number of " + record.get_name() + " is at position " + str(position))
            self.elementCount += 1
            return True

    def search(self, record):
        found = False
        position = self.hashFunction(record.get_number())
        self.comparisons += 1

        if self.table[position] is not None:
            if self.table[position].get_name() == record.get_name() and self.table[position].get_number() == record.get_number():
                found = True
                print("Phone number found at position {} and total comparisons are 1".format(position))
                return position

            else:
                position += 1
                if position >= self.size - 1:
                    position = 0

                while self.table[position] is not None or self.comparisons <= self.size:
                    if self.table[position].get_name() == record.get_name() and self.table[position].get_number() == record.get_number():
                        found = True
                        comparisons = self.comparisons + 1
                        print("Phone number found at position {} and total comparisons are {}".format(position, comparisons))
                        return position

                    position += 1
                    if position >= self.size - 1:
                        position = 0
                    self.comparisons += 1

        if not found:
            print("Record not found")
            return False

    def display(self):
        print("\n")
        for i in range(self.size):
            print("Hash Value: " + str(i) + "\t\t" + str(self.table[i]))
        print("The number of phonebook records in the Table are : " + str(self.elementCount))
