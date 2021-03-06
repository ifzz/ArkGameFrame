// -------------------------------------------------------------------------
//    @FileName         :    NFCDataList.h
//    @Author           :    Ark Game Tech
//    @Date             :    2012-03-01
//    @Module           :    NFCDataList
//
// -------------------------------------------------------------------------

#ifndef NFC_DATALIST_H
#define NFC_DATALIST_H

#include "NFIDataList.h"
#include "NFComm/NFPluginModule/NFGUID.h"

/**
 * @class   NFCDataList
 *
 * @brief   List of nfc data.
 *
 * @author  flyicegood
 * @date    2016/11/22
 */

class NFCDataList: public NFIDataList
{
public:
    NFCDataList();

    NFCDataList(const std::string& str, const std::string& strSplit);

    NFCDataList(const NFCDataList& src);
    NFCDataList(const NFIDataList& src);

    virtual ~NFCDataList();

    // 添加
    virtual bool Append(const NFIDataList& src);
    virtual bool Append(const NFIDataList& src, const int start, const int count);

    // 添加
    virtual bool Append(const NFIDataList::TData& TData);

    // 清空
    virtual void Clear();

    // 是否为空
    virtual bool IsEmpty() const;

    // 数据数量
    virtual int GetCount() const;

    // 合并
    virtual bool Concat(const NFIDataList& src);

    //////////////////////////////////////////////////////////////////////////
    const NF_SHARE_PTR<NFIDataList::TData> GetStack(const int index) const;

    // 数据类型
    virtual TDATA_TYPE Type(const int index) const;
    int TypeInt(const int index) const;
    //数据类型检测
    virtual bool TypeEx(const  int nType, ...) const;

    virtual bool Split(const std::string& strData, const std::string& strSplit);

    virtual bool Add(const NFINT64 value);
    virtual bool Add(const double value);
    virtual bool Add(const std::string& value);
    virtual bool Add(const NFGUID& value);
    virtual bool Add(const Point3D& value);

    virtual bool Set(const int index, const NFINT64 value);
    virtual bool Set(const int index, const double value);
    virtual bool Set(const int index, const std::string& value);
    virtual bool Set(const int index, const NFGUID& value);
    virtual bool Set(const int index, const Point3D& value);

    // 获得数据
    virtual NFINT64 Int(const int index) const;
    virtual double Double(const int index) const;
    virtual std::string ToString(const int index) const;
    virtual const std::string& String(const int index) const;
    virtual const NFGUID& Object(const int index) const;
    virtual const Point3D& Point(const int index) const;

    virtual bool ToString(std::string& strOut, const std::string& strSeparator) const;

protected:
    void AddStatck();
    void InnerAppendEx(const NFIDataList& src, const int start, const int end);
    bool ValidIndex(int index) const;
};

#endif