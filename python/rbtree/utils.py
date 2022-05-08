from abc import abstractmethod
from functools import total_ordering
from typing import Any, Generic, TypeVar

Cmp = TypeVar('Cmp', bound='Comparable')

@total_ordering
class Comparable(Generic[Cmp]):
    @abstractmethod
    def __lt__(self: Cmp, other: Cmp) -> bool: ...

    @abstractmethod
    def __gt__(self: Cmp, other: Cmp) -> bool: ...

