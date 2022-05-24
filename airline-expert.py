from experta import *
from random import randint


class windspeed(Fact):
    """windspeed of an airplane"""
    pass


class AMS(KnowledgeEngine):

    @Rule(windspeed(P(lambda x: x < 5)))
    def good(self):
        print("Winspeed is lower than safe, Landing success")

    @Rule(windspeed(P(lambda x: x == 5)))
    def caution(self):
        print("Winspeed is equal to safe, Perfect Landing")

    @Rule(windspeed(P(lambda x: x > 5)))
    def worst(self):
        print("Winspeed is higher than safe, Landing may crash")


engine = AMS()
engine.reset()
engine.declare(windspeed(randint(0, 12)))
engine.run()
