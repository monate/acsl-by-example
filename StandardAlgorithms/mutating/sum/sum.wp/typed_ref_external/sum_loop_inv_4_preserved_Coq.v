(* ---------------------------------------------------------- *)
(* --- Preservation of Invariant (file sum.c, line 13)    --- *)
(* ---------------------------------------------------------- *)
Require Import ZArith.
Require Import Reals.
Require Import BuiltIn.
Require Import bool.Bool.
Require Import int.Int.
Require Import int.Abs.
Require Import int.ComputerDivision.
Require Import real.Real.
Require Import real.RealInfix.
Require Import real.FromInt.
Require Import map.Map.
Require Import Qedlib.
Require Import Qed.
Require Import WP_basics.
Require Import Memory.
Require Import Cint.

Require Import A_SumAxiomatic.

Goal
  forall (i_0 n_0 : Z),
  forall (Malloc_0 : array Z),
  forall (Mint_0 : farray addr Z),
  forall (a_0 : addr),
  let x_0 := (2147483647 * i_0)%Z in
  let x_1 := (2147483647 * n_0)%Z in
  let x_2 := ((L_Sum Mint_0 a_0 i_0%Z))%Z in
  let a_1 := (shift a_0 i_0%Z) in
  let x_3 := (Mint_0.[ a_1 ])%Z in
  let x_4 := (x_2 + x_3)%Z in
  ((i_0 < n_0)%Z) ->
  ((0 <= i_0)%Z) ->
  ((i_0 <= 4294967294)%Z) ->
  ((i_0 <= n_0)%Z) ->
  ((n_0 <= 4294967295)%Z) ->
  ((x_0 <= x_1)%Z) ->
  ((linked Malloc_0)) ->
  ((is_uint32 i_0%Z)) ->
  ((is_uint32 n_0%Z)) ->
  ((0 <= x_2)%Z) ->
  ((x_2 <= 2147483647)%Z) ->
  ((is_uint32 (1%Z + i_0%Z)%Z)) ->
  ((is_sint32 x_2)) ->
  ((is_sint32 x_3)) ->
  ((x_2 <= ((Cdiv (2147483647 * (i_0 - 1)) n_0)))%Z) ->
  ((valid_rd Malloc_0 ((shift a_0 0%Z)) n_0%Z)) ->
  ((valid_rd Malloc_0 a_1 1%Z)) ->
  (((-2147483648) <= x_4)%Z) ->
  ((0 <= x_4)%Z) ->
  ((x_4 <= 2147483647)%Z) ->
  (((i_0 * x_3) <= 2147483647)%Z) ->
  (((n_0 * x_3) <= 2147483647)%Z) ->
  ((is_sint32 x_4)) ->
  (forall (i_1 : Z), ((i_1 < n_0)%Z) -> ((0 <= i_1)%Z) ->
   ((0 <= (Mint_0.[ (shift a_0 i_1%Z) ]))%Z)) ->
  (forall (i_1 : Z), let x_5 := (n_0 * (Mint_0.[ (shift a_0 i_1%Z) ]))%Z in
   ((i_1 < n_0)%Z) -> ((0 <= i_1)%Z) ->
   (((0 <= x_5)%Z) /\ ((x_5 <= 2147483647)%Z))) ->
  (((2147483647 + x_0) <= x_1)%Z).

Proof.
  auto with zarith.
Qed.
