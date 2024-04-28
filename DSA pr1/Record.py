class Record:
    def __init__(self, name=None, number=None):
        self._name = name
        self._number = number

    def get_name(self):
        return self._name

    def get_number(self):
        return self._number

    def set_name(self, name):
        self._name = name

    def set_number(self, number):
        self._number = number

    def __str__(self):
        return "Name: {}\tNumber: {}".format(self._name, self._number)
