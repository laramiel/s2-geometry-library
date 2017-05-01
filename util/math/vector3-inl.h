// Copyright 2003 Google, Inc.
// All Rights Reserved.
//
//
// A simple class to handle vectors in 3D
// The aim of this class is to be able to manipulate vectors in 3D
// as naturally as possible and make calculations readable.
// For that reason, the operators +, -, * are overloaded.
// (Reading a = a + b*2 - c is much easier to read than
// a = Sub(Add(a, Mul(b,2)),c)   )
// The code generated using this vector class is easily optimized by
// the compiler and does not generate overhead compared to manually
// writing the operations component by component
// (e.g a.x = b.x + c.x; a.y = b.y + c.y...)
//
// Operator overload is not usually allowed, but in this case an
// exemption has been granted by the C++ style committee.
//
// Please be careful about overflows when using those vectors with integer types
// The calculations are carried with the same type as the vector's components
// type. eg : if you are using uint8 as the base type, all values will be modulo
// 256.
// This feature is necessary to use the class in a more general framework with
// VType != plain old data type.

#ifndef UTIL_MATH_VECTOR3_INL_H__
#define UTIL_MATH_VECTOR3_INL_H__

#include "util/math/vector3.h"

#include <algorithm>
using std::min;
using std::max;
using std::swap;
using std::reverse;

#include <cmath>
using std::abs;

#include "base/basictypes.h"
#include "base/logging.h"
#include "base/template_util.h"
#include "base/type_traits.h"
#include "util/math/mathutil.h"
#include "util/math/vector2.h"
#include "util/math/vector4.h"

template <typename VType>
Vector3<VType>::Vector3() {
  Clear();
}

// because swig is complaining about no destructor
template <typename VType>
Vector3<VType>::~Vector3() {}

template <typename VType>
Vector3<VType>::Vector3(const VType x, const VType y, const VType z) {
  c_[0] = x;
  c_[1] = y;
  c_[2] = z;
}

template <typename VType>
Vector3<VType>::Vector3(const Vector2<VType> &vb, VType z) {
  c_[0] = vb.x();
  c_[1] = vb.y();
  c_[2] = z;
}

template <typename VType>
Vector3<VType>::Vector3(const Self &vb) {
  c_[0] = vb.c_[0];
  c_[1] = vb.c_[1];
  c_[2] = vb.c_[2];
}

template <typename VType>
Vector3<VType>::Vector3(const Vector4<VType> &vb) {
  c_[0] = vb.x();
  c_[1] = vb.y();
  c_[2] = vb.z();
}

template <typename VType>
template <typename VType2>
Vector3<VType> Vector3<VType>::Cast(const Vector3<VType2> &vb) {
  return Self(VType(vb[0]), VType(vb[1]), VType(vb[2]));
}

template <typename VType>
bool Vector3<VType>::operator==(const Self &vb) const {
  return (c_[0] == vb.c_[0]) && (c_[1] == vb.c_[1]) && (c_[2] == vb.c_[2]);
}

template <typename VType>
bool Vector3<VType>::operator!=(const Self &vb) const {
  return (c_[0] != vb.c_[0]) || (c_[1] != vb.c_[1]) || (c_[2] != vb.c_[2]);
}

template <typename VType>
bool Vector3<VType>::aequal(const Self &vb, FloatType margin) const {
  return (abs(c_[0] - vb.c_[0]) < margin) && (abs(c_[1] - vb.c_[1]) < margin) &&
         (abs(c_[2] - vb.c_[2]) < margin);
}

template <typename VType>
bool Vector3<VType>::operator<(const Self &vb) const {
  if (c_[0] < vb.c_[0]) return true;
  if (vb.c_[0] < c_[0]) return false;
  if (c_[1] < vb.c_[1]) return true;
  if (vb.c_[1] < c_[1]) return false;
  if (c_[2] < vb.c_[2]) return true;
  return false;
}

template <typename VType>
bool Vector3<VType>::operator>(const Self &vb) const {
  return vb.operator<(*this);
}

template <typename VType>
bool Vector3<VType>::operator<=(const Self &vb) const {
  return !operator>(vb);
}

template <typename VType>
bool Vector3<VType>::operator>=(const Self &vb) const {
  return !operator<(vb);
}

template <typename VType>
void Vector3<VType>::Set(const VType x, const VType y, const VType z) {
  c_[0] = x;
  c_[1] = y;
  c_[2] = z;
}

template <typename VType>
Vector3<VType> &Vector3<VType>::operator=(const Self &vb) {
  c_[0] = vb.c_[0];
  c_[1] = vb.c_[1];
  c_[2] = vb.c_[2];
  return (*this);
}

template <typename VType>
Vector3<VType> &Vector3<VType>::operator+=(const Self &vb) {
  c_[0] += vb.c_[0];
  c_[1] += vb.c_[1];
  c_[2] += vb.c_[2];
  return (*this);
}

template <typename VType>
Vector3<VType> &Vector3<VType>::operator-=(const Self &vb) {
  c_[0] -= vb.c_[0];
  c_[1] -= vb.c_[1];
  c_[2] -= vb.c_[2];
  return (*this);
}

template <typename VType>
Vector3<VType> &Vector3<VType>::operator*=(const VType k) {
  c_[0] *= k;
  c_[1] *= k;
  c_[2] *= k;
  return (*this);
}

template <typename VType>
Vector3<VType> &Vector3<VType>::operator/=(const VType k) {
  c_[0] /= k;
  c_[1] /= k;
  c_[2] /= k;
  return (*this);
}

template <typename VType>
Vector3<VType> Vector3<VType>::MulComponents(const Self &vb) const {
  return Self(c_[0] * vb.c_[0], c_[1] * vb.c_[1], c_[2] * vb.c_[2]);
}

template <typename VType>
Vector3<VType> Vector3<VType>::DivComponents(const Self &vb) const {
  return Self(c_[0] / vb.c_[0], c_[1] / vb.c_[1], c_[2] / vb.c_[2]);
}

template <typename VType>
Vector3<VType> Vector3<VType>::operator+(const Self &vb) const {
  return Self(*this) += vb;
}

template <typename VType>
Vector3<VType> Vector3<VType>::operator-(const Self &vb) const {
  return Self(*this) -= vb;
}

template <typename VType>
VType Vector3<VType>::DotProd(const Self &vb) const {
  return c_[0] * vb.c_[0] + c_[1] * vb.c_[1] + c_[2] * vb.c_[2];
}

template <typename VType>
Vector3<VType> Vector3<VType>::operator*(const VType k) const {
  return Self(*this) *= k;
}

template <typename VType>
Vector3<VType> Vector3<VType>::operator/(const VType k) const {
  return Self(*this) /= k;
}

template <typename VType>
Vector3<VType> Vector3<VType>::CrossProd(const Self &vb) const {
  return Self(c_[1] * vb.c_[2] - c_[2] * vb.c_[1],
              c_[2] * vb.c_[0] - c_[0] * vb.c_[2],
              c_[0] * vb.c_[1] - c_[1] * vb.c_[0]);
}

template <typename VType>
VType &Vector3<VType>::operator[](const int b) {
  DCHECK(b >= 0);
  DCHECK(b <= 2);
  return c_[b];
}

template <typename VType>
VType Vector3<VType>::operator[](const int b) const {
  DCHECK(b >= 0);
  DCHECK(b <= 2);
  return c_[b];
}

template <typename VType>
void Vector3<VType>::x(const VType &v) {
  c_[0] = v;
}

template <typename VType>
VType Vector3<VType>::x() const {
  return c_[0];
}

template <typename VType>
void Vector3<VType>::y(const VType &v) {
  c_[1] = v;
}

template <typename VType>
VType Vector3<VType>::y() const {
  return c_[1];
}

template <typename VType>
void Vector3<VType>::z(const VType &v) {
  c_[2] = v;
}

template <typename VType>
VType Vector3<VType>::z() const {
  return c_[2];
}

template <typename VType>
VType *Vector3<VType>::Data() {
  return reinterpret_cast<VType *>(c_);
}

template <typename VType>
const VType *Vector3<VType>::Data() const {
  return reinterpret_cast<const VType *>(c_);
}

template <typename VType>
VType Vector3<VType>::Norm2(void) const {
  return c_[0] * c_[0] + c_[1] * c_[1] + c_[2] * c_[2];
}

template <typename VType>
typename Vector3<VType>::FloatType Vector3<VType>::Norm(void) const {
  return sqrt(Norm2());
}

template <typename VType>
Vector3<VType> Vector3<VType>::Normalize() const {
  static_assert(!base::is_integral<VType>::value, "must_be_floating_point");
  VType n = Norm();
  if (n != 0) {
    n = 1.0 / n;
  }
  return Self(*this) *= n;
}

template <typename VType>
Vector3<VType> Vector3<VType>::Ortho() const {
  int k = LargestAbsComponent() - 1;
  if (k < 0) k = 2;
  Self temp;
  temp[k] = 1;
  return (this->CrossProd(temp)).Normalize();
}

template <typename VType>
int Vector3<VType>::LargestAbsComponent() const {
  Self temp = Fabs();
  if (temp[0] > temp[1]) {
    if (temp[0] > temp[2]) {
      return 0;
    } else {
      return 2;
    }
  } else {
    if (temp[1] > temp[2]) {
      return 1;
    } else {
      return 2;
    }
  }
}

template <typename VType>
Vector3<int> Vector3<VType>::ComponentOrder() const {
  Vector3<int> temp(0, 1, 2);
  if (c_[temp[0]] > c_[temp[1]]) swap(temp[0], temp[1]);
  if (c_[temp[1]] > c_[temp[2]]) swap(temp[1], temp[2]);
  if (c_[temp[0]] > c_[temp[1]]) swap(temp[0], temp[1]);
  return temp;
}

template <typename VType>
typename Vector3<VType>::FloatType Vector3<VType>::Angle(const Self &va) const {
  return atan2(this->CrossProd(va).Norm(), this->DotProd(va));
}

template <typename VType>
Vector3<VType> Vector3<VType>::Sqrt() const {
  return Self(sqrt(c_[0]), sqrt(c_[1]), sqrt(c_[2]));
}

template <typename VType>
Vector3<VType> Vector3<VType>::Fabs() const {
  return Self(abs(c_[0]), abs(c_[1]), abs(c_[2]));
}

template <typename VType>
Vector3<VType> Vector3<VType>::Abs() const {
  static_assert(base::is_integral<VType>::value, "use_Fabs_for_float_types");
  static_assert(static_cast<VType>(-1) == -1, "type_must_be_signed");
  static_assert(sizeof(VType) <= sizeof(int), "Abs_truncates_to_int");
  return Self(abs(c_[0]), abs(c_[1]), abs(c_[2]));
}

template <typename VType>
Vector3<VType> Vector3<VType>::Floor() const {
  return Self(floor(c_[0]), floor(c_[1]), floor(c_[2]));
}

template <typename VType>
Vector3<VType> Vector3<VType>::Ceil() const {
  return Self(ceil(c_[0]), ceil(c_[1]), ceil(c_[2]));
}

template <typename VType>
Vector3<VType> Vector3<VType>::FRound() const {
  return Self(rint(c_[0]), rint(c_[1]), rint(c_[2]));
}

template <typename VType>
Vector3<int> Vector3<VType>::IRound() const {
  return Vector3<int>(lrint(c_[0]), lrint(c_[1]), lrint(c_[2]));
}

template <typename VType>
void Vector3<VType>::Clear() {
  c_[2] = c_[1] = c_[0] = VType();
}

template <typename VType>
bool Vector3<VType>::IsNaN() const {
  return isnan(c_[0]) || isnan(c_[1]) || isnan(c_[2]);
}

template <typename VType>
Vector3<VType> Vector3<VType>::NaN() {
  return Self(MathUtil::NaN(), MathUtil::NaN(), MathUtil::NaN());
}

template <typename VType>
Vector3<VType> operator-(const Vector3<VType> &vb) {
  return Vector3<VType>(-vb[0], -vb[1], -vb[2]);
}

template <typename ScalarType, typename VType>
Vector3<VType> operator*(const ScalarType k, const Vector3<VType> &v) {
  return Vector3<VType>(k * v[0], k * v[1], k * v[2]);
}

template <typename ScalarType, typename VType>
Vector3<VType> operator/(const ScalarType k, const Vector3<VType> &v) {
  return Vector3<VType>(k / v[0], k / v[1], k / v[2]);
}

template <typename VType>
Vector3<VType> Max(const Vector3<VType> &v1, const Vector3<VType> &v2) {
  return Vector3<VType>(max(v1[0], v2[0]), max(v1[1], v2[1]),
                        max(v1[2], v2[2]));
}

template <typename VType>
Vector3<VType> Min(const Vector3<VType> &v1, const Vector3<VType> &v2) {
  return Vector3<VType>(min(v1[0], v2[0]), min(v1[1], v2[1]),
                        min(v1[2], v2[2]));
}

template <typename VType>
std::ostream &operator<<(std::ostream &out, const Vector3<VType> &va) {
  out << "[" << va[0] << ", " << va[1] << ", " << va[2] << "]";
  return out;
}

// TODO(user): Vector3<T> does not actually satisfy the definition of a POD
// type even when T is a POD. Pretending that Vector3<T> is a POD probably
// won't cause any immediate problems, but eventually this should be fixed.
PROPAGATE_POD_FROM_TEMPLATE_ARGUMENT(Vector3);

#endif  // UTIL_MATH_VECTOR3_INL_H__
