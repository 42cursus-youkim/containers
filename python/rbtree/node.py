from __future__ import annotations

from dataclasses import dataclass, field
from enum import IntEnum, auto
from functools import total_ordering
from typing import Generic, Iterator, TypeVar

from termcolor import colored

from .utils import Comparable


class NodeColor(IntEnum):
    RED = auto()
    BLACK = auto()
    NIL = auto()


T = TypeVar("T", int, Comparable)


@total_ordering
@dataclass
class Node(Generic[T]):
    value: T
    color: NodeColor = NodeColor.RED
    parent_: Node | None = field(default=None)

    def __post_init__(self):
        self.left: Node
        self.right: Node

        if self.color != NodeColor.NIL:
            # Nil nodes have dummy value None
            self.left = Node(value=None, color=NodeColor.NIL, parent_=self)  # type: ignore
            self.right = Node(value=None, color=NodeColor.NIL, parent_=self)  # type: ignore

    @property
    def is_nil(self) -> bool:
        return self.color == NodeColor.NIL

    @property
    def is_black(self) -> bool:
        return self.color in [NodeColor.BLACK, NodeColor.NIL]

    def is_full(self) -> bool:
        return not any([self.is_nil, self.left.is_nil, self.right.is_nil])

    def __str__(self) -> str:
        hl = "on_magenta" if self.is_black else "on_red"
        return colored(str(self.value), on_color=hl, attrs=["dark"])

    def __lt__(self, other: Node[T]) -> bool:
        return self.value < other.value

    def __gt__(self, other: Node[T]) -> bool:
        return self.value > other.value

    def in_order(self) -> Iterator[Node[T]]:
        if not self.is_nil:
            yield from self.left.in_order()
        yield self
        if not self.is_nil:
            yield from self.right.in_order()
