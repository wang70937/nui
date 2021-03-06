#pragma once



class TestFrameParser : public testing::Test
{
public:
    TestFrameParser()
    {
    }
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(TestFrameParser, Basic)
{
    // Parse BaseObj
    NInstPtr<NParser> parser(MemToolParam);
    NAutoPtr<NBaseObj> obj = parser->Parse(NULL, _T("@TestUI:TestFrame"));
    ASSERT_TRUE(obj != NULL);

    // Frame
    NAutoPtr<NFrame> frame = dynamic_cast<NFrame*>((NBaseObj*)obj);
    ASSERT_TRUE(frame != NULL);

    EXPECT_EQ(frame->GetId(), _T("TestFrame"));
    EXPECT_TRUE(frame->IsVisible());
    EXPECT_TRUE(frame->IsEnabled());

    const NRect& rect = frame->GetRect();
    EXPECT_EQ(rect.Left, 123);
    EXPECT_EQ(rect.Top, 34);
    EXPECT_EQ(rect.Width(), 220);
    EXPECT_EQ(rect.Height(), 330);
    EXPECT_FALSE(frame->IsAutoSize());

    // Text
    NTextAttr* textAttr = frame->GetTextAttr();
    TCHAR szText[100] = {0x6211, 0x53EA, 0x662F, 0x4E00, 0x4E2A, 0x6D4B, 0x8BD5};
    EXPECT_EQ(frame->GetText(), szText);
    EXPECT_EQ(textAttr->GetColor(), 0xff946542);
    EXPECT_EQ(textAttr->GetBgColor(), 0xff926872);
    EXPECT_EQ(textAttr->IsSingleLine(), false);
    EXPECT_EQ(textAttr->GetAlignFlags() & NTextAttr::TextAlignVCenter, NTextAttr::TextAlignVCenter);
    EXPECT_EQ(textAttr->GetAlignFlags() & NTextAttr::TextAlignHCenter, NTextAttr::TextAlignHCenter);
}
